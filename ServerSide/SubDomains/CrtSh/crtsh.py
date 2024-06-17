#!/usr/bin/python

from bs4 import BeautifulSoup # Requires to install bs4: pip install bs4
import requests
import re #Import to perform regular expressions.
from sys import argv

soup = BeautifulSoup(requests.get('https://crt.sh/?q='+argv[1]).text,'html.parser') # Parse the HTML.
lista = soup.find_all(string=re.compile(argv[1])) # We get all lines that matches our substring.
file = open(argv[1]+'.crtsh','w')

for item in range(2,len(lista)):
	file.write(lista[item]+'\n')

file.close