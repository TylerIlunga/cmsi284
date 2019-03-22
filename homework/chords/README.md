**CMSI 284** Computer System Organization/Systems Programming, Spring 2019

# Assignment 0326
Time to try your hand at some rudimentary C programming. This set has a touch of music theory just to keep things a little interesting.

## Background Reading
Pretty much all of the information you need can be found in Dr. Toal’s [Introduction to C](http://cs.lmu.edu/~ray/notes/c) page, as well as many other C programming sites on the web.

## For Submission: Oh Say Can You C
Write the requested C programs.

### chord.c
Write a C program, _chord.c_, that takes a command line argument which is the uppercase name of a piano key, and writes to standard output the major, minor, dominant 7th, and diminished 7th chords for that key. For simplicity, constrain note names exclusively to sharps.

Sample program invocation and output:

    $ ./chord F#
    F#: F# A# C#
    F#m: F# A C#
    F#7: F# A# C# E
    F#dim7: F# A C D#

If the wrong number of command line arguments is supplied, the program should respond as follows:

    $ ./chord
    This program requires exactly one command line argument.

Or:
 
    $ ./chord A B C D E
    This program requires exactly one command line argument.

If a non-existent or invalid piano key is provided, the program should respond as follows:

    $ ./chord bazinga
    No such key: bazinga

Or:
 
    $ ./chord f#
    No such key: f#

As with previous assignments, the grading of this assignment will be semi-automated, so it is very important that you adhere strictly to the specified output messages and format.

### interval.c
Write a C program, _interval.c_, that takes two command line arguments which are the names of two uppercase piano keys, assumes that the second key is higher than the first key, and writes to standard output the _interval_ between those two keys. The intervals are defined as follows:

| Keys Apart | Interval Name |
| ---------- | ------------- |
| 1 | minor second |
| 2 | major second |
| 3 | minor third |
| 4 | major third |
| 5 | perfect fourth |
| 6 | tritone |
| 7 | perfect fifth |
| 8 | minor sixth |
| 9 | major sixth |
| 10 | minor seventh |
| 11 | major seventh |
| 12 | perfect octave |

For simplicity, constrain note names exclusively to sharps. If the same key is given for both arguments, the output should be `perfect octave` because the second key is always assumed to be above the first one.

Sample program invocation and output:

    $ ./interval F# C
    F# to C is a tritone.

If the wrong number of command line arguments is supplied, the program should respond as follows:

    $ ./interval
    This program requires exactly two command line arguments.

Or:
 
    $ ./interval A C D
    This program requires exactly two command line arguments.

If a non-existent or invalid piano key is provided, the program should respond as follows:

    $ ./interval bazinga B
    No such key: bazinga

Or:

    $ ./interval D a
    No such key: a

The moment one invalid piano key is discovered, the program need not go further:
 
    $ ./interval f# Bar
    No such key: f#

As with previous assignments, the grading of this assignment will be semi-automated, so it is very important that you adhere strictly to the specified output messages and format.

## How to Turn it In
Commit your source code (and _just_ the source code)—_chord.c_ and _interval.c_—to this repository.

## Specific Point Allocations
This assignment is scored according to outcomes _2a_, _2b_, and _4a_ to _4f_ in the [syllabus](https://dondi.lmu.build/spring2019/cmsi284/cmsi284-spring2019-syllabus.pdf). For this particular assignment, graded categories are as follows:

| Category | Points | Outcomes |
| -------- | -----: | -------- |
| _chord.c_ | 50 points total | |
| • Compiles and runs without unexpected errors | 10 points | _4a_, _4d_ |
| • Correct program output | 25 points | _2a_, _2b_, _4a_, _4d_ |
| • Correct handling of invalid user input | 15 points | _2a_, _2b_, _4a_, _4d_ |
| _interval.c_ | 50 points total | |
| • Compiles and runs without unexpected errors | 10 points | _4a_, _4d_ |
| • Correct program output | 25 points | _2a_, _2b_, _4a_, _4d_ |
| • Correct handling of invalid user input | 15 points | _2a_, _2b_, _4a_, _4d_ |
| Hard-to-maintain or error-prone code | deduction only | _4b_ |
| Hard-to-read code | deduction only | _4c_ |
| Version control | deduction only | _4e_ |
| Punctuality | deduction only | _4f_ |
| **Total** | **100** |

Note that inability to compile and run to begin with will negatively affect the correctness of program output and proper handling of invalid user input.
