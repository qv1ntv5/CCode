### Descripción.

[Wpscan](https://github.com/wpscanteam/wpscan) es una herramienta que automatiza el escaneo del CMS Wordpress en busca de vulnerabilidades y plugins desactualizados.

Para nuestros intereses, el comando más interesante es:

```shell
wpscan --url <URLtarget> --enumerate p --detection-mode aggressive --api-token <WPApiKey>
```

Este comando enumera de forma agresiva (--detection-mode aggressive) los plugins (--enumerate p) de la web objetivo que contiene el CMS en cuestión (--url <URLtarget>) utilizando una API key de WpScan (--api-token <wpscanApiKey>)

Podemos conseguir una API key en la siguiente [página](https://wpscan.com/api/)