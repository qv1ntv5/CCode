### What is Directory Traversal And File Inclusion.

Is a Server-Side vulnerability that allows an attacker to read the contents of arbitrary files of the server which is running the application. This vulnerability is baed on improper sanitization of input given by user.

Is worth to mention that there is a similar vulnerability called File Inclusion, which not only allows to an attacker to read the content of an arbitry file but to include the content of the file in the workflow of the application. With a file inclusion, you could execute a PHP file within the server, with a directory traversa you only can display it contents.

In file inclusion there are common the usage of PHP functions like *include()* which are used to process the user's input without previous sanitization. There are two types for file inclusion:

- Local File Inclusion, for files which are within the server.
- Remote File Inclusion, for files which are in a remote server. This vulnerability involves other vulnerability called SSRF.

<br>

### CheatSheet.

- Try to display **/etc/hosts** in linux hosts or **C:\Windows\System32\drivers\etc\hosts** in Windows hosts.

- Try to add some backpaths

    ```text
    images/../../../../../../../../../../../etc/passwd
    ```

- If there is some extensión whitelist, try to add it with a null byte:

    ```text
    images/../../../../../../../../../../../etc/passwd%00php
    ```



