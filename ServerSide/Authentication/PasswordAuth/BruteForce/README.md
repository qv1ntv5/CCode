### Descripción.

Un **ataque de fuerza bruta consiste en un proceso por el cual un atacante utiliza un sistema de trial-error para averiguar credenciales de usuarios válidas**.
Generalmente, estos ataques se utilizan listas de diccionario de nombres de usuario y contraseñas que pueden estar hechas al azar o pueden estar basadas en el contenido encontrado en un proceso de enumeración del entorno web que se está atacando. 

Esto es especialmente útil **cuando conseguimos hacernos con algún documento que nos permita inferir las reglas de fortaleza de las credenciales** de la web.
<br>

### Presentación de herramientas.

Podemos utilizar diversas herramientas para poder realizar ataques de fuerza bruta:

- Para crear listas de diccionario válidas; 

    - [Crunch](https://www.kali.org/tools/crunch/) es una herramienta que te permite generar listas de cadenas de caracteres basadas en patrones que pasas a la herramienta a modo de argumentos, como iteraciones, repeticiones, adición de números o caracteres especiales, etc. Especialmente útil si conocemos las reglas de fortaleza de las contraseñas de una determinada compañía.

    - [Cewl](https://www.kali.org/tools/cewl/) es una herramienta que mapea el contenido HTML de un sitio web para generar una lista de palabras relacionadas con dicho sitio web para utilizarlas en procesos de fuerza bruta, ya sea fuzzing, autenticación, mapeo, etc.

    - [JohnTheRipper](https://www.openwall.com/john/) & [Hashcat](https://hashcat.net/hashcat/), dos conocidas herramientas de crackeo de contraseñas que tienen funcionalidades que permiten crear listas de candidatos basados en datos pasados a la herramienta de forma precedente.

    - Listas de diccionario predefinidas como el caso de [Rockyou.txt](https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt) o [Seclists](https://github.com/danielmiessler/SecLists) que pueden ser utilizadas a modo de candidatos a posibles contraseñas, fuzzing, etc.

    - Por último, podemos apoyarnos en herramientas dinámicas como [ChatGPT](https://chatgpt.com/) para crear rápidamente listas de candidatos.

<br>

- Para realizar ataques de fuerza bruta:

    - [BurpSuite](https://portswigger.net/burp) se trata de una herrmienta que tiene diversas características, entre ellas el [BurpIntruder](https://portswigger.net/support/using-burp-to-brute-force-a-login-page), el cual nos sirve para realizar ataques de fuerza bruta.

    - [Hydra](https://www.kali.org/tools/hydra/) es una herramienta que permite realizar ataques de fuerza bruta contra una serie de servicios en un servudor remoto (FTP, SSH, SMB, HTTP, etc) de forma flexible y customizable.

    - [NetExec](https://github.com/Pennyw0rth/NetExec), se trata de la continuación del proyecto de [CrackMapExec](https://www.kali.org/tools/crackmapexec/) y puede servir para realizar ataques de fuerza bruta o comprobar credenciales en determinados entornos.