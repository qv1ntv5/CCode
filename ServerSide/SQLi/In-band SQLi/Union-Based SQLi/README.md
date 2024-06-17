### Descripción

El Union-Based SQLi es un tipo de In-band SQLi en la que se utiliza el operador SQL UNION para poder inyectar queries SQL en un punto de inyección de la aplicación web.

Esto se produce porque en la query original se está utilizando el operador SQL SELECT, de forma que el operador UNION une a la primera sentencia SELECT una segunda sentencia SELECT permitiendo a un atacante exfiltrar datos de la base de datos.
<br>

### Requisitos de la técnica

**Esta segunda query SELECT debe cumplicar un conjunto de dos requisitos**:

- Debe tener el mismo número de columnas que la primera query.
- Los valores de cada campo deben de coincidir en tipo con los de primera query por columna.

Si tenemos la query SQL:

```sql
SELECT id, name, description from products;
```
Esta query obtiene valores de 3 columnas de una tabla. El primer valor es un tipo 'numeric' y el segundo y el tercero son 'string', con lo que si queremos anexar un UNION SELECT, deberemos incorporar tres campos, y solo podremos exfiltrar datos tipo 'string' de los dos últimos y los dos siguientes strings.

```sql
SELECT id, name, description from products UNION SELECT NULL, username, password from mysql.user;
```
<br>

### Metodología
#### 1. Descubriendo el número de columnas.

Esto significa que para poder inyectar payloads en un In-band Union-based SQLi, primero hay que detectar el número de columnas de la primera query.

Esto lo podemos conseguir con el SQL statement ORDER BY, el cual se utiliza para ordenar los contenidos que se muestran por una columna que se pasa por argumento, por ejemplo:

```sql
SELECT * FROM Products ORDER BY Price;
```

Así, podemos obtener el número de columnas indicando la columna a través de su índice, obtendremos un error en el momento en el que pasemos como argumento un número natural superior al número de columnas existentes en la query inicial.

Es decir, que si en el statement SELECT inicial hay tres columnas y pasamos:

```url
https://insecure-website.com/products?category=' ORDER BY 4 --//
```

Obtendremos un error del servidor lo cual quiere decir que había 3 columnas.

*En resúmen; probamos con **'ORDER BY n --//** hasta que se produzca un error y habrá **n - 1** columnas en la query principal*
<br>

Otro método que podemos probar es pasar tantos nulls como columnas haya  **'UNION SELECT null,...null** hasta **NO** obtener un error. Observemos que este proceso es factible debido a que el objeto NULL, como datatype, es compatible con cualquier otro datatype.

#### Extrayendo información.

Una vez sabemos el número de columnas de la query principal, tenemos que extraer información en una query anexada a través de la columna que tenga un datatype compatible con el tipo de dato que queremos extraer.

Para ello, supongámos que tenemos un In-band SQLi que responde a la siguiente inyección:

```
https://insecure-website.com/products?category=' UNION SELECT null,null,null
```

Entonces, podemos 