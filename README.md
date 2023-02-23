# CSCI 6708 - Assignment 3

## File structure:

```
-── code
    ├── Makefile
    ├── README.md
    ├── ext-acl.txt
    ├── ext-ip.txt
    ├── src
    │   ├── headers
    │   │   ├── ext-std-acl.h
    │   │   ├── ip.h
    │   │   └── std-acl.h
    │   ├── ext-std-acl.cpp
    │   ├── ip.cpp
    │   ├── main.cpp
    │   └── std-acl.cpp
    ├── std-acl.txt
    └── std-ip.txt
```

`.cpp` files are inside `src/` folder and all the headers are inside `src/headers`. The input files are in the top-most directory `code/`. 

## Setup the code

Download the file and maintain the above file structure. The files are uploaded to brightspace, github and git.cs.dal.ca. 

- [`Github repo`](https://github.com/gurukiran07/csci6708-acl)
- [`git.cs.dal.ca repo`](https://git.cs.dal.ca/jagata/csci6708-acl)

```
$ git clone git@github.com:gurukiran07/csci6708-acl.git
```

## Running the code

After cloning or downloading from brightspace change into `code/` directory. And run `make` to compile and run the code.

```
$ cd code/
code/ $ ls
Makefile        README.md       ext-acl.txt     ext-ip.txt      src             std-acl.txt     std-ip.txt
code/ $ make
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wall -Werror -I src/headers -c src/ip.cpp -o ip.o
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wall -Werror -I src/headers -c src/std-acl.cpp -o acl.o
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wall -Werror -I src/headers -c src/ext-std-acl.cpp -o ext.o
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wall -Werror -I src/headers ip.o acl.o ext.o src/main.cpp -o main
./main
================ STANDARD ACL ================
Packet from 162.16.3.7 permitted
Packet from 172.16.7.1 denied
Packet from 120.18.1.0 denied
Packet from 162.16.3.2 permitted
================     END      ================


================ EXTENDED ACL ================
Packet from 172.16.4.4 to 172.16.3.1 on port 20 denied
Packet from 172.16.4.4 to 172.16.3.5 on port 22 permitted
Packet from 172.25.3.1 to 172.16.3.4 on port 22 denied
================     END      ================
code/ $ make clean # Remove all object files and executable file main
rm -rf *.o main
```

## Testing the code

- To test standard ACL program edit the file `code/std-acl.txt` to add ACL rules and `code/std-ip.txt` to add IP for testing. 
- Edit the file `code/ext-acl.txt` for testing extended ACL by adding ACL rules and `code/ext-ip.txt` to add source, destination IPs and port number. 