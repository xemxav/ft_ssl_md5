# ft_ssl_md5

This project aims to re code the hashing functions md5 and sha256.

It creates an executable that emulates the behavior of the md5 and shasum command.

##### Usage : 
```
./ft_ssl
usage: ft_ssl command [command opts] [command args]
```

You need to choose between ```md5``` and ```sha256```, then the different option flags and a argument.

* no argument : reads on STDIN
* ```-p``` : echoSTDINtoSTDOUTand append the checksum toSTDOUT
* ```-q``` : quiet mode
* ```-r``` : reverse the format of the output.
* ```-s``` : print the sum of the given string

##### Exemples : 

```
./ft_ssl md5 -s "hashing a string"
MD5 ("hashing a string") = 383b48008920d474d8bac6139438c74a
```
```
./ft_ssl sha256 -s "hashing a new string"
SHA256 ("hashing a new string") = 72202acd73432a6bf944f6d0fcc6143fd78a674bb0f533ac387cdd40dbf90d37
```

##### Main take away:
* Understanding of hashing algorithms like md5 and sha256/
* Parsing and option flag management.
* Project structure and use of a dispatcher of function pointers. 