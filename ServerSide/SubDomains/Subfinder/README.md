### How to use SubFinder

Subfinder is a pasive enumeration tool (this is, it doesn't perform request to the server that is hosting the domain) that uses external API services in order to gather information about a desired domain.

- First of all, we have to download the lastest release from the following [link](https://github.com/projectdiscovery/subfinder/releases).

- Then, we launch for the first time the binary in order to get the config file created:

	```bash
	ubuntu@ubuntu:~/Downloads/subfinder_2.6.5_linux_amd64$ ./subfinder -d "www.exampleorg"
	
	               __    _____           __         
	   _______  __/ /_  / __(_)___  ____/ /__  _____
	  / ___/ / / / __ \/ /_/ / __ \/ __  / _ \/ ___/
	 (__  ) /_/ / /_/ / __/ / / / / /_/ /  __/ /    
	/____/\__,_/_.___/_/ /_/_/ /_/\__,_/\___/_/
	
			projectdiscovery.io
	
	[INF] Current subfinder version v2.6.5 (latest)
	[INF] Loading provider config from /home/ubuntu/.config/subfinder/provider-config.yaml <---
	[INF] Enumerating subdomains for www.exampleorg
	[...]
	```

- In the config file we find that we have to add our API key to each service in order to make subfinder to be able to make the request to his API.


	```bash
	ubuntu@ubuntu:~/Downloads/subfinder_2.6.5_linux_amd64$ cat /home/ubuntu/.config/subfinder/provider-config.yaml
	bevigil: []
	binaryedge: []
	bufferover: []
	builtwith: []
	c99: []
	censys: []
	certspotter: []
	chaos: []
	chinaz: []
	dnsdb: []
	dnsrepo: []
	facebook: []
	fofa: []
	fullhunt: []
	github: []
	hunter: []
	intelx: []
	leakix: []
	netlas: []
	passivetotal: []
	quake: []
	redhuntlabs: []
	robtex: []
	securitytrails: []
	shodan: []
	threatbook: []
	virustotal: []
	whoisxmlapi: []
	zoomeyeapi: []
	```

	We add our apikey between the brackets and our tool is ready to find valid subdomains of a desired subdomain.
