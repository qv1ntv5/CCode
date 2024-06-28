### Descripción

Autenticación es el proceso de verificación la identidad de un cliente. Conviene no confundir autenticación con autorización, el cual es el proceso de comprobar si un cliente tiene o no permisos para acceder a un recursos y cuyo contenido se cubre en otro apartado.

La comprobación de tu identidad se establece a través de una o varias de las siguientes vías:

- Pregúntandote algo que sabes como una **password**
- Aludiendo a algo que tienes como un **security token en otro dispositivo**
- Comprobando algo que eres como **datos biométricos**

Las vulnerabilidades de autenticación descansan fundamentalmente en dos pilares fundamentales:

- Los mecanismos de autenticación son débiles porque no protegen adecuadamente contra ataques de fuerza bruta.

- Los fallos lógicos o una codificación deficiente en la implementación permiten que un atacante eluda por completo los mecanismos de autenticación. A esto a veces se le llama "autenticación rota".