COS 214: Software Modelling
Assignment 3
Name: Caleb Johnstone
--> TASK 3 <--
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN THE PROGRAM:

-> use makefile command: make run

MY MAIN PROGRAM (main.cpp):

A DynamicArray of size 10 is declared.
The even numbers 0,2,...,18 are inserted into the array in order.
The array is then printed.
All of the elements that are multiples of 6 are removed.
The array is then printed.
The array is cleared.
The multiples of 3: 0,3,...,27 are inserted into the array in order.
The array is then printed.

The print function:

A DynamicArrayIterator of type int is used to iterate through each element of the DynamicArray and current() is used to be able to print the value at the 
currentIndex.

I changed the current function to return a variable of type T so that it can be used to return values for different variable types.
I added a function called getCurrentIndex that returns the current index in the array, to be used for printing. currentIndex is used to traverse through
the array held as an attribute in the DynamicArrayIterator class.
