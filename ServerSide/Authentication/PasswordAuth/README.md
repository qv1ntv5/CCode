### Descripción

Recordemos que los procesos de autenticación basados en contraseña requieren de que un usuario con una cuenta ingrese a menudo un string para poder meterse en dicha cuenta. Esta cuenta o 'username' está asociado a dicha contraseña y el poder dar esta contraseña es prueba suficiente como para demostrar la propiedad sobre dicha cuenta.

En esta sección vamos a ver un conjunto de métodos para explotar un conjunto de defectos en estos portales de logeo.

### HTTP basic authentication.

En el contexto de una transacción de datos a través del protocolo HTTP, el **basic access authentication** es un método por el cual, el HTTP User Agent proporciona unas credenciales en formato 'username:password' codificadas en base64:

```
Authorization: Basic <credentials>
```

Este método de autenticación está obsoleto y es notablemente inseguro aunque sigue siendo implementando por muchos sitios web.

Veremos cómo esta característica puede ser vulnerable en otros apartados.
