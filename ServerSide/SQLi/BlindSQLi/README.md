### Descripción.

El Blind SQLi se produce cuando una aplicación es vulnerable a SQLi pero no devuelve datos interesantes en la respuesta HTTP a la request en la que se produce el ataque.
<br>

### Detección.

Esta vulnerabilidad se detecta mediante la provocacion de time delays. Podemos introducir las siguientes líneas extrapolando la técnica utilizada en el error-based SQLi, pero esta vez provocando un Time-Delay:

```
'; IF (1=2) WAITFOR DELAY '0:0:10'--
'; IF (1=1) WAITFOR DELAY '0:0:10'--
```

De esta forma, se evalua una condición y si esta es cierta se produce un time delay, si no no.
<br>

### Extrayendo información.

Así, si tenemos información acerca del contenido de la base de datos, podemos efectuar extración de información acerca del contenido de la contraseña del usuario administrador:

```
'; IF (SELECT COUNT(Username) FROM Users WHERE Username = 'Administrator' AND SUBSTRING(Password, 1, 1) > 'm') = 1 WAITFOR DELAY '0:0:{delay}'--
```

La línea anterior evalua si el primer caracter de la contraseña del usuario administrador está por encima de m en orden alfabético y si es así, genera un delay.

