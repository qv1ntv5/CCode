### Descripción.

Las Error-Based SQLi **son tipos de SQLi donde la única respuesta por parte del servidor cuando el atacante intenta interactuar con la base de datos es un mensaje de error**. Por este motivo, este tipo de ataques están a medio camino entre un Blind SQLi y un In-Band SQLi.

El objetivo del atacante cuando se enfrenta a este tipo de SQLi consiste en inducir al servidor a devolver un error para inferir información del mismo. Por ejemplo; consideremos la siguiente query SQL:

```
' AND (SELECT CASE WHEN (1=2) THEN 1/0 ELSE 'a' END)='a
' AND (SELECT CASE WHEN (1=1) THEN 1/0 ELSE 'a' END)='a
```

Estos casos realizan la evaluación de una sentencia condicional en base al valor de una entidad booleana. Si la conidición evaluada es cierta, se desencadena un error que, por la idiosincrasia de la vulnerabilidad, se muestra por pantalla al atacante permitiendole inferir que el valor de la condición era cierto, en caso contrario no se muestra nada.

Así, el atacante puede inferir información acerca del contenido de la base de datos con una query como la siguiente:

```
' AND (SELECT CASE WHEN (Username = 'Administrator' AND SUBSTRING(Password, 1, 1) > 'm') THEN 1/0 ELSE 'a' END FROM Users)='a
```

En la SQL query anterior, se toma la contraseña del usuario Administrador y se mide si el substring compuesto por el primer caracter está por encima de la letra 'm' en orden alfabetico.

<br>

### Materializando el proceso.

#### 1. Conditional Errors

Podemos a través del BurpIntruder ir capturando letra a letra la contraseña del usuario administrador a través de un conjunto de peticiones que rápidamente acotan el rango de caracteres posibles para cada letra de la contraseña.
<br>

#### 2. Respuesta embebida en el mensaje de error.

En algunos casos, el contenido de tu query puede volver representada en el mensaje de error, por esta razón, podemos intentar realizar una operación que genere un error en la que aparezca el resultado de dicha operación:

```sql
CAST((SELECT example_column FROM example_table) AS int)
```

En la query anterior se utiliza el operador 'CAST' para castear un tipo de dato 'string' a 'int', esta operación no puede realizarse y generará un error como el siguiente:

```
ERROR: invalid input syntax for type integer: "Example data"
```
<br>


