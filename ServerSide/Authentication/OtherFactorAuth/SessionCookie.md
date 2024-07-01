### Descripción.

Una forma cómoda de evitar que el usuario se tenga que logear en un sitio web una y otra vez consiste en guardar en su navegador una pieza de información con el objetivo de reconocer al usuario en contextos de cierre de ventana.

Esta pieza de información se denomina llamada **cookie**, concretamente, en nuestro caso se denomina **cookie de sesión** y en muchos casos la mala implementación de este token puede conducir a fallas de seguridad. Por ejemplo, puede ser que la construcción de esta cookie sea fácilmente predecible, una combinación del nombre de usuario y la contraseña codificados en base64.

### Detección.

- Siempre que tengamos la oportunidad de optar a una cookie de sesión debemos intentar decodificarla con el objetivo de ver si se puede reconstruir.

- En cualquier otro término, si un sitio web es vulnerable a XSS se pueden robar estas cookies de sesión.

- También hay que comprobar si el sitio web está gestionado por un CMS o un framework que tenga documentada cómo se fabrica la cookie de sesión.