# Deadfish Interpreter
Simple deadfish interpreter written in C

## Instructions
| cmd | desc                        |
| --- | --------------------------- |
| i   | increment accumulator in 1  |
| d   | decrement accumulator in 1  |
| s   | square the accumulator      |
| o   | output the accumulator      |

## Usage
pass a file for the dfi.
```sh 
$ ./dfi code.df 
```

dfi also has a idle mode in dep/ folder, but is not maintained

## Build
After Download dfi.c and Makefile, run:
```sh
$ make
```
