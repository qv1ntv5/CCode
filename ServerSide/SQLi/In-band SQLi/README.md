### Descripción.

El In-band SQLi o simplemente SQLi es la forma más simple de SQLi y ocurre cuando el atacante puede utilizar el mismo canal para realizar el ataque y para recibir los datos.

Existen distintos tipos de In-band SQLi:

- Error-Based SQLi
- Union-Based SQLi

### Métodos de detección.

Para detectar un In-band SQLi podemos empezar introduciendo una **comilla simple** preferentemente utilizando el BurpRepater en el punto de inyección para comprobar si recibimos una respuesta anómala por parte del servidor.

```
https://insecure-website.com/products?category=Gifts'
```

El siguiente paso será introducir un término de comentario para ver si la respuesta vuelve a la normalidad, en ese caso, significará que hemos interferido con una query y que podemos introducir datos en ella:

```
https://insecure-website.com/products?category=Gifts'--//
```

Sin embargo, los payloads pueden ser más específicos dependiendo del tipo de SQLi.

