#!/bin/bash
# This script attemps to make more confortable the use of subfinder.

{
    ./subfinder -d "$1" -o $1.subdomains &>/dev/null

} || {

    echo 'Usage: ./subfinder.sh "domain"'
}

# With {} || {} structure we attemp to make a try/catch exception performance, if command1 doesn't succed, then command2.
