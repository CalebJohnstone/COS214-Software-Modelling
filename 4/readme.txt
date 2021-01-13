Name: Caleb Johnstone
Student Number: u19030119
COS 214: Assignment 4

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN THE PROGRAM:

-> use makefile command to just run: make run
   --> this will run the following command (as of submitting): ./main 501561 427 all
      ---> this command follows the following format: ./main <random_seed1> <random_seed2> <apply>
            where:

            <random_seed1> is the srand seed that determines the buttons that are pressed to control the RC car and RC plane in main.cpp
            <random_seed2> is the srand seed that determines the buttons that are pressed to control the RC rocket
            <apply> determines whether or not to apply a request to the first RemoteControlVehicle that can handle the request or to all that can do so,
                    this will be done by using <apply> equal to "all" or "first" (without quotes) respectively. So this paramter can be changed to have a different
                    policy for which vehicles the request is applied to.

                    The value of <apply> is written to the text file called: "config.txt" to be read later in the course of the program         

When changing these command line arguments - the command: make run can still be used as the updated values will be used since they are saved in the makefile
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
TASK 6 PICTURE: the picture is called "Task 6.png"

Arrays of buttons are created for controlling the car and plane, as well as the rocket.
The array indices can be viewed as the numbers on the buttons on the universal remote. 

Button class:
--> press():  executes its assigned command
--> undoPress() : executes the opposite of its assigned command, for example: the opposite of TurnOn is TurnOff. This button press could be
                  pressing some sort of shift button at the same time as the current button to have the opposite effect, for example.

The RemoteControlVehicles have a name to identify them when sending requests using the Chain of Responsibility pattern. The name servers as a way of
seeing what the effect of changing the <apply> command line argument. For example, the program currently does the following in regards to the Chain of Responsibility pattern:

- the already made car is "Lightning McQueen" and the already made plane  is "VSS Unity"
- 2 new cars are made: "Chick "Thunder" Hicks" and "Ferrari"
- 2 new planes are made: "Fighter Jet" and "Crop duster"
- buttons are pressed to turn on the 2 new planes
- the vehicles are added to the car called "Lightning McQueen" in the following order: "VSS Unity", "rocket adapter", "Chick "Thunder" Hicks", "Fighter Jet", "Crop duster" and "Ferrari"
- buttons are pressed to send the fly and speed commands down the chain created
- buttons are pressed to reverese the actions of the requests in the previous point

with <random_seed1> = 501561, <random_seed2> = 427, <apply> = all the following happens:

- "VSS Unity" is off and therefore cannot fly. The other 2 planes fly since they are on and all planes should fly since <apply> = all
-  "Lightning McQueen" is on and therefore can speed. The other 2 cars cannot speed since they are currently off.

- "VSS Unity" is off and therefore cannot be stopped from flying. The other 2 planes stop flying since they are on and all planes should stop flying since <apply> = all
- "Lightning McQueen" is on and therefore can be stopped from speeding. The other 2 cars cannot be stopped since they are currently off.

with <random_seed1> = 501561, <random_seed2> = 427, <apply> = first the following happens:

-  "VSS Unity" is off and therefore cannot fly. Only "Fighter Jet" flies since it is the first plane that is currently on.
- "Lightning McQueen" is on and therefore can speed. In this case where <apply> = first, it does not matter that the other cars are
   off since "Lightning McQueen" is the first on car.

- "VSS Unity" is off and therefore cannot be stopped from flying. Only "Fighter Jet" stops flying since it is the first plane that is currently on.
- "Lightning McQueen" is on and therefore can be stopped from speeding. In this case where <apply> = first, it does not matter that the other cars are
   off since "Lightning McQueen" is the first on car.