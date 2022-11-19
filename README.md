# brainFlipper
brainFlipper is simple brainf\*ck interpreter written in C.
It can execute your code as long as it is syntactically correct.
Currently it does not give error message on wrong syntax and will have undefined behavior on wrong syntax.
Some sample brainf\*ck program are also provided.
## Features
1) Non command charaters are allowed and are treated as comment.
2) Supports nested loops. for eg. ` [->[->+<]<]`.
3) Fast.

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
$ brainc programs/mandelbrot.b
$ brainc programs/hello_world.bf
```
## Uninstall
```
$ make uninstall
```
