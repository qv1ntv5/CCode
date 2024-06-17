### How to use Httpx

Often, in subdomain enumeration we gather subdomains that are no longer available to explore. Httpx is a tool that, among other things, allow us to quickly check and filter those of the subdomains that are no longer valid.

We get from the following [link](https://github.com/projectdiscovery/httpx) the lastest binary and we use it as follows:

```bash
./httpx -l subdomainlist.txt -sc -silent -nc | grep -v 40* | grep -v 50* > validsubdomains.txt
```

Is worth to mention that we have to merge the subdomains obtained with other tools in one file and then exclude the repeated lines with 'sort -u' command before using this tool.