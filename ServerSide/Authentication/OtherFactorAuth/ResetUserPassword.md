### Descripción.

Es común que algunas páginas web contengan una funcionalidad para resetear la contraseña. Para poder resetear la contraseña de un usuario, evidentemente se necesita una forma de comprobar la autenticidad del mismo y por ello, esta funcionalidad es inherentemente peligrosa.
<br>

### Detección.

De nuevo, ninguna medida es más seguro de lo que lo es su implementación y el reseteo de contraseña es una funcionalidad que puede ser implementada de diversas maneras inseguras.

- **Contraseña al email**

Algunos sitios web envían la nueva contraseña al email del usuario que lo solicita. Este método es susceptible de ser vulnerable a ataques estilo MITM. En este caso, exploraremos la funcionalidad de reseteo de contraseña en busca de parámetros que indiquen el email y nos permitan cambiarlo o cosas del estilo.

- **Reseteando contraseñas con URL**

Otro método consiste en enviar al usuario una URL donde pueden cambiar la contraseña de su cuenta de su usuario.

Una mala implementación de esta técnica consistiría en enviar una URL fácilmente predecible.

```
http://vulnerable-website.com/reset-password?user=victim-user
```

De esta forma, se podría cambiar la contraseña de dicho usuario fácilmente habilitando la funcionalidad y luego accediendo a dicha URL.

Una forma más segura es ofuscar la URL con el objetivo de volverla impredecible para nadie que no la reciba directamente.
<br>

### Password Reset poisoning.

Este es un tipo distinto de debilidad por la cual un atacante es capaz de manipular la funcionalidad de reseteo de contraseña para mandar el link a un dominio bajo su control, robando el token de reseteo de contraseña y por extensión, la cuenta en sí.

Esta técnica explota el hecho de que se confía que, al mandar el link de reseteo de contraseña al email de un usuario, sólo dicho usuario tiene acceso al recipiente donde se encuentra el link. 

Sin embargo, si el link se genera de forma dinámica con contenido que un usuario puede controlar entonces existe el riesgo de que la construcción del link sea emponzoñada o incluso desviada hacia un atacante.

### Conclusiones.

En cualquier caso, la funcionalidad de reseteo de contraseña es una funcionalidad inherentemente vulnerable y merece ser examinada con rigor en busca de fallas de implementación como nombres de usuario en la request, etc.

