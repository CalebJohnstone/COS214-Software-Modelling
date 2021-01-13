COS 214: Software Modelling
Assignment 3
Name: Caleb Johnstone
--> TASK 4 <--
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN THE PROGRAM:

-> use makefile command: make run

SMALL CHANGE TO test.cpp:

When loggedIn is true and input equals 1: cin >> message; was only putting the characters before the first space into the message variable and causing an
infinite loop for messages with spaces in them. To fix this I used getline, once to ignore the newline character entered as part of the prompt and the second
time to assign the message to the message variable. This solved the issue for me.
The same goes for any other response to a prompt that could have a space in it.
