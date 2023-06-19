#General
This is a simple generic stack implementation in pure C. 
Even at that it's about 4x faster than the C++ `<stack.h>` counterpart.
The test function of filling the stack up to 5294967295 and emptying it
took about 3 minutes on an i7 processor, while the counterpart in C++ 
took 12 minutes.  <br>

The stack implementation is the basic introduction to a lot of things
like object oriented programming, or, like here, to generic programming
in C. It's easy to understand and has countrless practical applications. <br>

There are multiple ways to implement the stack. One obvious choice is
to have a pointer to the top of the stack.
