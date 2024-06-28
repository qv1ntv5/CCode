### Descripción

CMS son las siglas de Content Management System o en español, Sistema de Gestión de Contenidos. Este es un software que permite administrar un sitio web.

Desde la perspectiva de ciberseguridad, los CMSs son propopensos a tener fallas de seguridad conocidas, sobre todo cuando este no está correctamente actualizado. Las pruebas a realizar dependen de cada CMS, pero entre las más habituales están;

- Exploits públicos.
- Fallas de autenticación.
- API REST mal configurada

Entre otras.
<br>

### Detección

A la hora de detectar si en un sitio web existe un CMS administrándolo podemos emplear las siguientes herramientas y métodos.

- [Wappalyzer](https://www.wappalyzer.com/), esta extensión permite desgranar los componentes de un sitio aportando en muchos casos versión.
- Escáneres web automáticos como Nikto o Nuclei.
- Código fuente en busca de referencias a ciertos CMSs como Wordpress.
- Páginas de login.
