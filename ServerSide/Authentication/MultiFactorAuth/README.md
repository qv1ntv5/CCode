### Descripción.

En algunos sitios web se requieren a los usuarios más de un paso de autenticación. Además de poner la contraseña, referiendo a algo que saben, mandan un segundo código a un segundo dispositivo, aludiendo a algo que el usuario tiene.

Esta medida refuerza la seguridad de la autenticación de la aplicación aunque esta seguridad no se extiende más allá de la correcta implementación de la misma. Una mala implementación de esta técnica puede conducir a vulnerabilidades como veremos a continuación.


La forma de segunda autenticación más frecuente es el  **two-factor authentication token**, que consiste en la mayoría de los casos en un código o patron envíado a un segundo dispositivo que se debe introducir en el sitio web después de la contraseña con el objetivo de validar doblemente la identidad del usuario.
<br>

### Bypassing two-factor authentication.

Una mala implementación de esta clase de solucciones puede dar lugar a debilidades y fallas de seguridad que son propias de cada caso.

Por ejemplo, puede ser que el 2FA esté basado en un código débil, fácilmente predecible (como por ejemplo un número de 4 dígitos), si esto se da conjuntamente sin medidas de protección contra ataques de fuerza bruta, entonces se obtiene que se puede enviar un código correcto sin necesidad de tener acceso a él.

En otros casos puede ser que el sitio web no verifique adecuadamente qué usuario está emitiendo el código de segunda autenticación, es decir, puede ser que el factor 2FA esté asociado a un parámetro en la HTTP request que indique el usuario al que está referido, de esta forma, podemos logearnos en nuestra cuenta y recibir nosotros mismos el factor de segunda autenticación:

```HTTP
POST /login-steps/second HTTP/1.1
Host: vulnerable-website.com
Cookie: account=carlos
...
verification-code=123456
```

Y cambiar la request para autenticarnos como otro usuario evadiendo así este 2FA factor:

```HTTP
POST /login-steps/second HTTP/1.1
Host: vulnerable-website.com
Cookie: account=victim-user
...
verification-code=123456
```
