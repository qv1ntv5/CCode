### What is Code/Command Injeciton.

This are both an *Injection* type vulnerabilities, the differences relies on the type of data getting injected.

- In **Code Injection** vulnerability you are injecting code lines from the programming language which the application is based on (python, php, java, etc)
- In **Command Injection** vulnerability you are injecting commands from the OS of the host which is hosting the application
<br>

### CHeatsheet
- First, try to introduce some key values like, simple coute ('), double coutes ("), semicolon (;), etc in order to see if you manage to trigger any error or unexpect behaviour.
- If you manage to trigger some unexpect behaviour you can try to inject code if you know the language the application is working with or with the OS commands.

    The logic would be, finish the current line and add a new one; for example:

    ```
    http://172.16.66.128/codeexec/example1.php?name=";system(%27id%27);//
    ```

    In the line above we can see that we are terminating the line with **";** and with **system('id');//** we are introucing our line of code and commenting the rest of it.

- With some Command Injection vulnerabilities, there are some counter measures that sanitized the input from the user, but frecuently this only affects to the first line of data. An hipotetic attacker could bypass this measure by adding a salt line with **%0a** byte.

- Also is better to use a proxy or netcat to not follow redirections.