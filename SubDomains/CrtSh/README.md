Crt.sh is a website that allows to gather information from a domain through a certificate-based search. crt.sh provides a searchable database of certificate transparency logs. Certificate Transparency is an Internet security standard and open source framework for monitoring and auditing digital certificates.

We can use this website to get subdomains from a given domain, using the following script we can do a request and then parse the response to only get the subdomains.

```python
from bs4 import BeautifulSoup
import requests
import re #Import to perform regular expressions.
  
soup = BeautifulSoup(requests.get('https://crt.sh/?q=viajeselcorteingles.es').text,'html.parser') # Parse the HTML.
lista = soup.find_all(string=re.compile("viajeselcorteingles")) # We get all lines that matches our substring.
for item in range(2,len(lista)):
	print(lista[item])
```

The handicap using this tool is that we get a lot of subdomains that not necesarily are up. We have to filter the output with httpx in order to get the status code and remove from the list those that are denied or forbbiden.