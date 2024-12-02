### Descripción.

SQL injection (SQLi) is a web security vulnerability that allows an attacker to  interfere with an SQL query that remote server does to retrieve information to the user through improper sanitized data, disclosuring backend's information or even RCE.

### Detección automática. SQLMap.

En las subcarpetas de esta sección del repositorio podemos encontrar información acerca de cómo detectar una SQLi manualmente. Sin embargo, estos métodos pueden servir a modo de introducción rápida pero desde luego no definitiva y menos a modo de proceso de detección exhaustivo.

En su lugar, es preferible utilizar [SQLmap](https://github.com/sqlmapproject/sqlmap) para llevar a cabo un proceso de detección exhaustivo. Podemos apoyarnos en guías por internet, o incluso ChatGPT, acerca de su uso ya que con frecuencia se necesitan varios escaneos que van poco a poco incrementando en complejidad hasta explotar el SQLi en cuestión.
<br>

### CheatSheet.


- At first, introduce a cuote (') or double coutes (") in order to trigger an error instead of retrieve no results.
- Once we find an injection point, we launch SQLMap.
