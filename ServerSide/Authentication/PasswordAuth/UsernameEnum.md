### Descripción.

Otro apartado de la debilidad de sistemas de autenticación basados en contraseña consiste en los cambios de comportamiento del servidor en base al nombre de usuario introducido durante la fase de autenticación. Esto inicialmente nos permitiría enumerar nombres de usuarios válidos en una fase previa al ataque de fuerza bruta.
<br>

### Detección.

Para detectar cambios en el comportamiento del servidor HTTP que nos puedan permitir inferir la validez de un nombre de usuario nos fijamos en los siguientes detalles:

- **Status Code**; El código de respuesta de un intento se le presupone el mismo para la mayoría de los intentos de logeo en un ataque de fuerza bruta. Un código de respuesta distinto con frecuencia suele ser identificador de una respuesta distinta por la validez de las credenciales o del nombre de usuario.

- **Error Messages**; Con frecuencia un intento de logeo fallído devuelve un mensaje de error por defecto que nos indica la incorrección de las credenciales usadas. Si el servidor HTTP está mal configurado, este mensaje de error puede ser sutílmente distinto del mensaje de error convencional. Este cambio puede ir desde 
