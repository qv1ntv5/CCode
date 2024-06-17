#!/usr/bin/python3
from bs4 import BeautifulSoup
import urllib
import requests
import sys

# This script attemps to perform a mapping job over a webapplication by catching all the paths present on the webpage and collect it in an array and displayin them.

html_page = requests.get(sys.argv[1]).text
soup = BeautifulSoup(html_page, features="lxml")

print("[+] Printing href:")
for link in soup.findAll('a'):
    print("---> "+str(link.get("href")))

for link in soup.findAll('link'):
    print("---> "+str(link.get("href")))

print("\n")
print("[+] Printing imgsrc:")
for link in soup.findAll('img'):
    print("---> "+str(link.get("src")))

print("\n")
print("[+] Printing scriptsrc:")
for link in soup.findAll('script'):
    print("---> "+str(link.get("src")))