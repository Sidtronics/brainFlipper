# brainFlipper
brainFlipper is simplest brainf\*ck interpreter you would ever find.
Which means it can execute your code as long as it is syntactically correct.
It wont give error message on wrong syntax but it will do something else which will be explained below.
Some sample brainf\*ck program are also provided.
## Features
1) Non command charaters are ignored and treated as comment.
2) Supports nested loops. for eg. ` [->[->+<]<]`.
3) Program can be terminated midway using unmatched `']'` more on this below.

## Installation

##### Download
```
$ git clone https://github.com/Sidtronics/brainFlipper
$ cd brainFlipper
```
##### Build and Install
```
$ make
$ sudo make install
$ make clean
```
## Usage
`$ brainc <path/to/src>`
eg:
```
$ brainc hello_world.bf
$ brainc sample_progs/hello_world.bf
```
## Note
1. When unmatched `'['` is found program will behave as if there was extra `']'` inserted at the end.
For eg. `+++[->+<` will execute as if it was `+++[->+<]`.

2. When unmatched `']'` is found program will terminate and will not execute any further command.
This behaviour is intentional and can be used as a break point for debugging purposes. 

## Uninstall
```
make uninstall
```
