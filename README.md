# term-graph-lib: A text-based graphing tool written in C

## Repo tree

```
term-graph-lib
├── ex
│   ├── lin.c      Linear function examples
│   └── sqr.c      Square function examples
└── src
    ├── graph.c    Graph source function file
    └── graph.h    Graph source header file
```

## What is it?

`term-graph-lib` is a library for function graphing in the terminal in C.

## How does it work?

`term-graph-lib` consists of a set of C headers and source files.

Below are the examples of compiling and running `term-graph-lib/ex` files.

### Linear functions

```
$ gcc ex/lin.c src/graph.c; ./a.out
Name:    A linear function of y = -2*x + (3)
X-label: X values
Y-label: Y values
x.....................^......................
.xx...................|......................
...xx.................|......................
....xxx...............|......................
......xxx.............|......................
........xxx...........|......................
..........xx..........|......................
............xxx.......|......................
..............xx......|......................
................xx....|......................
..................xx..|......................
...................xxx|......................
----------------------xxx------------------->
......................|.xxx..................
......................|...xxx................
......................|.....xx...............
......................|.......xx.............
......................|.........xx...........
......................|...........xx.........
......................|.............xx.......
......................|..............xxx.....
......................|.................xx...
......................|..................xxx.
......................|....................x.
......................|......................
```

### Square functions

```
$ gcc ex/sqr.c src/graph.c; ./a.out
Name:    Square function y=x^2
X-label: X values
Y-label: Y values
x.....................^......................
.x....................|....................x.
..x...................|...................x..
...x..................|..................x...
....x.................|.................x....
.....x................|................x.....
......xx..............|..............xx......
.......xx.............|.............xx.......
........xxx...........|...........xxx........
..........xx..........|..........xx..........
............xx........|........xx............
..............xxx.....|.....xxx..............
----------------xxxxxxxxxxxxx--------------->
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
......................|......................
```

## How do I use it?

To use it `term-graph-lib`, simply import the files into your project and call the functions within it.

The functions are listed below:

| Function      | Use case                                       |
| ------------- | ---------------------------------------------- |
| createGraph2D | Create the graph character array and return it |
| drawGraph2D   | Display the graph character array              |
| drawGraphInfo | Display the graph information                  |
