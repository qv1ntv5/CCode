### What is LDAP.

LDAP is an application protocol used for accessing and maintaining distributed directory information services over a network. These directories typically store structured information about users, groups, devices, and other resources in an organization which is ideal for centralized networks such as Active Directory.

- Null Bind, some LDAP server authorized NULL Bind, if Null values are sent, the LDAP server will proceed to bind connection. This can be achieve removing the autentication parameters from the requests.
- The other way to hack LDAP is to perform ![LDAP injection](https://brightsec.com/blog/ldap-injection/) over a field.