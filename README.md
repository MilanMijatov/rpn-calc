# rpn-calc
A Command-Line Reverse Polish Notation Calculator.

To compile:

gcc main.c -lm -o rpncalc

To run:

rpncalc <tokens>

Each token corressponds to a single number or operator delimited by a space.

For example:

rpn calc 5 4 +

Consists of 3 tokens; <5>, <4> and <5>.

Which results in an output of 9.
