Lab8
====

### Overview
During this lab, you will combine the previous laboratory assignments and program your robot to autonomously 
navigate through a maze. On the last day of the lab, each section will hold a competition to see who can solve 
the maze the fastest. The fastest time in ECE 382 will have their name engraved on a plaque in the CSD lab. Believe 
it or not, the main goal of this lab is for you to have some fun with computer engineering!

###Requirements

You must write a program that autonomously navigates your robot through a maze (Figure 1) while meeting the following requirements:

Your robot must always start at the home position.
Your robot is considered successful only if it finds one of the three exits and moves partially out of the maze.
A large portion of your grade depends on which door you exit.
Door 1 - Required Functionality
Door 2 - B Functionality
Door 3 - A Functionality
You cannot hit a wall!
Bonus! Navigate from the A door back to the entrance using the same algorithm.
You cannot hit a wall!
Your robot must solve the maze in less than three minutes.
Your robot will be stopped if it touches the wall more than twice.
Your robot must use the IR sensors to find its path through the maze.

Do not step onto the maze since the floor will not support your weight. You will notice the maze floor is cracked 
from cadets who ignored this advice.

###Prelab
The Prelab can be found attached. I did this on time and recieved a 9 out of 10 on this section.

###Required Functionality

For the Required Functionality, I ended up going with a wall hugging algorithm for my robot. The video can be seen below.

<embed width="440" height="420" type="application/x-shockwave-flash" src="http://v8.tinypic.com/player.swf?file=2hgd27n&s=8"><br><font size="1"><a href="http://tinypic.com/player.php?v=2hgd27n&s=8">Required Functionality</a>

A rough schematic of the robot can be seen below. Note that the Heat sink/GND is not connected to anything but itself. This was a mistake on my part and it should be tied to the common ground of the circuit.

![alt text](http://i58.tinypic.com/2rfzrxg.jpg)

My design process was to have the robot turn left and right to maintain a certain distance from the wall it was hugging (the left wall in this case), and then have it turn right if it ran directly into a wall. This design approach did not work, and what ended up happening is that my center sensor was very sensitive and ended up constantly turning right while all of the above was happening. Oddly enough it ended up working and I was able to get Required Functionality and even B Functionality. I did not record B functionality though as I was falsely informed that B functionality could not touch a wall. (mine touched the wall only once for B Functionality) I ended up getting the robot through the A functionality door as well, but it touched the wall twice so I tried finding solutions to that problem.

Originally I was going to try tweaking my code just barely to see if I could get my processes smoothed out, but I could not get the left sensor to cooperate the way I would have liked. Afterward I tried coming up with a state machine where the robot would more or less move in a straight line, detect a wall straight ahead, and then move in a direction depending on its state. A series of 90 degree turns going left, right, right, left, (and then repeating the same process) would have solved both A functionality and Bonus Functionality, and I started making progress towards those ends (straight lines and slightly off turns) but after a while my robot started getting wonky again and none of my previous code would work. It was as this point I called it quits.

###Documentation: C2C Erik Thompson suggested I use a wall hugging algorithm and he mentioned that having threshold values could have this accomplish. C2C Ruprecht suggested the use of states for the robot to accomplish the maze by only using the center sensor. He also let me use his robot (this was approved by Dr. York and Capt Trimble).
