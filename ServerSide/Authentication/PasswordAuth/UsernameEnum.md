### Descripción.

Otro apartado de la debilidad de sistemas de autenticación basados en contraseña consiste en los cambios de comportamiento del servidor en base al nombre de usuario introducido durante la fase de autenticación. Esto inicialmente nos permitiría enumerar nombres de usuarios válidos en una fase previa al ataque de fuerza bruta.
<br>

### Detección.

Para detectar cambios en el comportamiento del servidor HTTP que nos puedan permitir inferir la validez de un nombre de usuario nos fijamos en los siguientes detalles:

- **Status Code**; El código de respuesta de un intento se le presupone el mismo para la mayoría de los intentos de logeo en un ataque de fuerza bruta. Un código de respuesta distinto con frecuencia suele ser identificador de una respuesta distinta por la validez de las credenciales o del nombre de usuario.

- **Error Messages**; Con frecuencia un intento de logeo fallído devuelve un mensaje de error por defecto que nos indica la incorrección de las credenciales usadas. Si el servidor HTTP está mal configurado, este mensaje de error puede ser sutílmente distinto del mensaje de error convencional. Este cambio puede ir desde 

- **Response times**; Si el nombre de usuario es correcto pero la contraseña, puede derivar en una comprobación ulterior que desencadene un delay que se puede objetivamente medir con el tiempo de diferencia entre la request y la response.

- **Account lock**; Si realizando un ataque de fuerza bruta obtenemos que una cuenta se ha bloqueado, significa que la cuenta de hecho tiene 
<br>

### Materalizando el proceso.

Estas tres características se pueden medir a través del [BurpIntruder](https://portswigger.net/burp/documentation/desktop/tools/intruder/results). Este posee un conjunto de opciones entre las que se encuentran HTTP Response, length, presencia o ausencia de ciertas expresiones. Más información en el enlace dejado anteriormente.