### Descripción.

El **/wp-json** se trata del directorio raíz de la API REST del CMS de Wordpress. 
<br>

### Qué es una API REST.

Una API REST es una API; una interfaz de comunicación entre aplicaciones, adaptada al diseño REST; Representational State Transfer, que se trata a su vez de un diseño de interfaces para conectar aplicaciones a través del protocolo HTTP. 

Es decir, **una API REST es una API basada en el protocolo HTTP que actúa a modo herramienta para que los desarrolladores puedan interactuar, configurar o extraer datos de un programa online**.

Entre las características de REST podemos encontrar:

- Crea una petición HTTP que contiene toda la información necesaria, es decir, **un REQUEST a un servidor tiene toda la información necesaria y solo espera una RESPONSE**.

- **Todos los objetos se manipulan vía URI**.

Desde una perspectiva de ciberseguridad, tener una API REST expuesta y mal configurada puede permitir que un usuario no autenticado interactúe con los datos de dicho CMS llegando a comprometer la integridad, confidencialidad y disponibilidad de los datos hosteados por dicho CMS.
<br>

### Explotando la vulnerabilidad.

Si encontramos el /wp-json habilitado podemos intentar realizar las siguientes pruebas:

- Enumeración de usuarios del Wordpress:

    ```bash
    curl http://blog.example.com/wp-json/wp/v2/users
    ```

- Información de un blog en el Wordpress:

    ```bash
    curl http://blog.example.com/wp-json/oembed/1.0/embed?url=POST-URL
    ```


<br>

