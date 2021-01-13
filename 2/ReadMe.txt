COS 214: Software Modelling
Assignment 2

Name: Caleb Johnstone
Student Number: u19030119
Email: caleb.johnstone@tuks.co.za
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
MAKEFILE COMMAND TO RUN THE MAIN PROGRAM: make run

COMMAND LINE ARGUMENTS USED IN MAIN.CPP:

Index	Value

1		startLevel
2		random number generator seed
3		number of operations

------
The provided makefile contains the following line: ./main 5 257270 20 (this is only for Section A and C)
This line is run when using the make run command. This command means that the startLevel is 5, random seed is 257270 and the number of operations is 20. This line
can be changed to run different simulations for the coronavirus Pandemic object in main.cpp
===================================================================================================
MAIN.CPP:

Random numbers have been used to generate 20 operations, so either increasing or decreasing the level of the pandemic. If the level is increased then the
takeAction method is called afterwards. takeAction is not called after decreasing the level.

Once the coronavirus object is done with its operations, another Pandemic object is declared called "slammer". This object is used to run another simulation
of increasing and decreasing the levels for a pandemic. The changes 2D array determines whether the level is increased or decreased at each iteration of
80 operations.

The addition of outputting the poster made in Section C happens in the Pandemic class, the main function is unaware of this change and therefore did not need to
be modified as the added behaivour was handeled in the Pandemic class and not main.cpp. As a result of this the State Machine diagram does not need to be
updated as main.cpp still performs the same operations. The displaying of the poster is not part of main.cpp and therefore is not included in the state machine
diagram for main.cpp

TEXTFILES:

The textfiles called: "nonePoster.txt", "level1Poster.txt", "level2Poster.txt", "level3Poster.txt", "level4Poster.txt", "level5Poster.txt"
are used to provide the text for the main ImageElement objects (the first one in the array held in the BaseImage class) for their respective BaseImage
that are the posters being printed.

EXPLINATION OF FUNCTIONS:

The following functions have been given an explination as it may not be immediately obvious what their purpose is from just looking at the UML diagrams
as well as them being important details as to how the system functions and these functions were not explicitly stated in the specification:

-> BaseImage::addElement(imageElement Poster*): void

add a ImageElement object to the next available position of the BaseImage::elements array

-> BaseImage::BaseImage(filename: string)

create a BaseImage object from the given textfile. The textfile format is as follows:

    Line 1: number of ImageElements
    *<colour>,height#width
    <ImageElement pixels (text and border)>
    *<colour>,height#width
    <ImageElement pixels (text and border)>
    .
    .
    .
	
The first line contains the number of ImageElements that this BaseImage contains.
The lines of the form: *<colour>,height#width describe the colour that particular ImageElement will be and what the height and width of its text is.

The BaseImage contains in its elements array ImageElements which then in turn have ImageAdditions added to them so that images of a mask (Mask class),
thermometer (TemperatureCheck class), hand sanitiser (UseHandSanitiser class) and/or the water droplet (WashHands class) can be added to the text defined in
the textfile for each ImageElement in the BaseImage.

-> BaseImage::addToElement(number: int, addition: ImageAdditions*): void

used to add to the respective ImageElement, a Concrete Decorator -> so one of: Mask, UseHandSanitiser, WashHands, TemperatureCheck

this function is used in the Pandemic class with number = 1 to add to the first ImageElement in the BaseImage's elements array so that all of the ImageAdditions
are at the top and the ImageElements containing the text are at the bottom of the poster. Since this function is declared as public, it can be used by main.cpp with
1 < number <= numElements to add ImageAdditions to other ImageElements in the elements array. This was not done just to keep all of the ImageAdditions at the
top of the poster so that it would be easier to identify the differences between the posters.

->ImageElement::ImageElement(pixelCharacters: char**, height: int, width: int)

each ImageElement has a grid of pixels (characters) that stores the text defined in the textfile read from when creating the ImageElement in the BaseImage
constructor. A 2D array was used rather than a 1D array (char*) so that the ImageElement can have its base text span over more than one line.

--------------------------------------------
The following table shows when certain ImageAdditions are added to the poster variable in the Pandemic class (BaseImage* poster) and when they are omitted:
(Y: yes, N: no) -> for if the ImageAdditions is included or not

						No Level Level 1 Level 2 Level 3 Level 4 Level 5
ImageAdditions class

WashHands				Y			Y		Y		Y		Y		Y
UseHandSanitiser		N			Y		Y		Y		Y		Y
Mask					N			N		Y		Y		Y		Y
TemperatureCheck		N			N		N		Y		Y		Y


Below are the messages and the posters for each level:
(the row of asterisks (*) are the top and bottom borders for the posters)

------------------------ No level: ------------------------ 

The country is at no level: Normal Living
********************************************************************************
      ,
   ,'   `.
  %       %
  :        :
  ".     ."
    `-.-'

 WASH YOUR HANDS


--- The country is at no pandemic level, but you
must still be careful to wash your hands to be
clean and safe at all times. -------------------



--------- You no longer need to use hand sanitiser
regularly, just when touching surfaces that may be
unclean. -----------------------------------------

********************************************************************************
The country is at no level: The level cannot be decreased.

------------------------ Level 1: ------------------------ 

The country is at level1: Very few cases
********************************************************************************
      ,
   ,'   `.
  %       %
  :        :
  ".     ."
    `-.-'

 WASH YOUR HANDS


----- Remain cautious at level 1.
It is not strictly necessary to
wear a mask at all times when
outside. ------------------------

********************************************************************************
Slammer Virus has started to spread. We are making all citizens wear masks and social distancing. Stopping all international flights

------------------------ Level 2: ------------------------ 

Slammer Virus has started to spread. We are making all citizens wear masks and social distancing. Stopping all international flights


The country is at level2: Take caution
********************************************************************************
      ,
   ,'   `.
  %       %
  :        :
  ".     ."
    `-.-'

 WASH YOUR HANDS


----- Be carefull at level 2.
You no longer need to check
your temperature when you are
not feeling well. Still make
sure you social distance,
especially if you are sick -
even if it is just the flu.

********************************************************************************
Slammer Virus is spreading faster. We are forced to close public spaces.

------------------------ Level 3: ------------------------ 

The country is at level3: Moderate number of cases, make sure you are wearing a mask
********************************************************************************
      ,
   ,'   `.
  %       %
  :        :
  ".     ."
    `-.-'

 WASH YOUR HANDS


-- Level 3 still requires
keeping up social distancing
and only going out when it is
essential. ------------------



--- Keep doing the following things:

-> Washing your hands regularly
-> Use hand sanitiser when using doors
and touching objects in public
-> Check your own temperature when you
do not feel well. Do not just rely on
when your temperature is taken when
entering a public place
-> Wear a mask at ALL times when you
are outside

********************************************************************************

------------------------ Level 4: ------------------------ 

The country is at level4: There are quite a bit of cases, take all necessary precautions.
********************************************************************************
      ,
   ,'   `.
  %       %
  :        :
  ".     ."
    `-.-'

 WASH YOUR HANDS


-- We still have far to go as a country --



-- REMEMBER THAT THE FOLLOWING HABITS ARE VERY IMPORTANT:

-> washing your hands with soap regularly
-> using hand sanitiser, keep one with yourself so that
you do not have to rely on being provided it in public
-> wear a mask at all times that you are not at home
-> check your temperature if you are feeling sick or
flustered

********************************************************************************
Slammer Virus is dangerous. Enforcing a strict lockdown.

------------------------ Level 5: ------------------------ 

The country is at level5: Don’t go outside unless you have to
********************************************************************************
      ,
   ,'   `.
  %       %
  :        :
  ".     ."
    `-.-'

 WASH YOUR HANDS


---> EXTREME CAUTION: this is a national emergency <-----------



--- Make these actions part of your daily routine to keep safe ---

-> washing your hands with soap regularly
-> using hand sanitiser, keep one with yourself so that
you do not have to rely on being provided it in public
-> wear a mask at all times that you are not at home
-> check your temperature if you are feeling sick or
flustered

********************************************************************************
Slammer Virus is extremely dangerous. Deploying the army. Shutting down the economy