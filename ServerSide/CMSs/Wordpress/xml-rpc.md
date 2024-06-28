### Descripción.

XML-RPC se trata de una API de Wordpress que utiliza el HTTP como protocolo de transmisión de datos y el lenguaje XML como mecanismo de codificación y representación.

Se trata a menudo de una característica obsoleta reemplazada por la implementación de la API REST de wp-json en Wordpress.

<br>

### Explotación.

Si un usuario no autenticado puede interactuar con ella puede llegar a realizar una enumeración de los contenidos del wordpress.

- **Detección**:

    En primer lugar, con BurpSuite habilitado, realizamos una petición desde el navegador a 

    ```
    https://example.com/xml-rpc.php
    ```

    E interceptamos la request. 

    Seguidamente, cambiamos el tipo de request de POST a GET.

    Por último, añadimos el siguiente código XML para listar los métodos habilitados para 

    ```xml
    <methodCall>
    <methodName>system.listMethods</methodName>
    <params></params>
    </methodCall>
    ```

- **Explotación**:

    Si la API está habilitada, podemos seguir esta [guía](https://book.hacktricks.xyz/network-services-pentesting/pentesting-web/wordpress) para intentar explotar esta vulnerabilidad.