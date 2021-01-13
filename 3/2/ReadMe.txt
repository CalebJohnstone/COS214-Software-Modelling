COS 214: Software Modelling
Assignment 3
Name: Caleb Johnstone
--> TASK 2 <--
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN THE PROGRAM:

-> use makefile command: make run

MY MAIN PROGRAM (main.cpp):

I have defined an enumation type called Direction that can take on thevalues: up, down, left or right.

There is an array of directions called moves.

A prison area is created that has a height and width of 5.

The prisoner for the prison area is stored.

The moves array is looped through and the runTowards function for the prisoner object with the current move from the moves array as an argument. This will move
the prisoner in the direction stored at the current index in the moves array. Each time the prisoner moves the resulting layout of the prison area is printed.

Border Guards are respresented by a + sign. It should be noted that it is impossible for the prisoner to move onto one of the corners where the border guards
stand as once the prisoner is on one of the walls they are pushed back one space. In order to get to a corner, the prisoner has to move onto one wall and then
move again either vertically or horizontally dependending on the situation. For example: to get to the top-left corner the prisoner could move to the left wall,
so their x-coordinate is zero and then move up to (0,0). But this is not possible as the prisoner will be pushed by the border guard at (0,0) to (1,y) where y is
the y-coordinate for the prisoners previous position: (0, y)
Therefore the prisoner is either moved back in the x-dimension or the y-dimension and not both.

The grid for the prison area can be viewed as starting at (0,0) for the top-left corner and has increasing y-coordinates as you move down and increasing
x-coordinates as go right. In a 5x5 grid, the bottom-left corner is (0,4), the bottom-right corner is (4,4) and the top-right corner is (4,0).
The x-coordinate shows how far across to the right the prisoner is and the y-coordinate shows how far down the prisoner is from (0,0).

SEQUENCE DIAGRAM:

The sequence diagram shows a situation where the prisoner goes onto either the left or the right wall and is moved one space in the x-dimension to be inside
the prison area again. The interactions and messages sent are only shown for the prisoner and one of the border guards for simplicity, but the same process
is done for all 4 border guards. If the prisoner were to step onto the top or bottom border then they would be moved one space in the y-dimension.
