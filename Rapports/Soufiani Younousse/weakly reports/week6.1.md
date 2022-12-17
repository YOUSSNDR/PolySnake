## <p align=center> Session 6
<ins>06/12</ins>

I have worked home on the new programm [snake_WalkV3](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/snake%20walkV3/snake%20walkV3.ino) as planed in the last session.

the goal in this new program was to make a list of angle which would have been followed by every servomotors with a shift between them in order to mimic the snake ondulation.
the issue was that i had not found a proper way to put all the servomotors in a loop.
Therefore I needed conditions in order for the loop to work as intended.
Also we needed to control the speed of those servomotors.

I tried to make a class ([move.h](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/snake%20walkV3/move.h) [move.cpp](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/snake%20walkV3/move.cpp))to resolve the issues of how to follow the list but the conditions case i have putted where not recognised by the c++ language.

To help me with the program my coworker lead me to a link of someone which had already worked on a snake robot before.
[programofWillDonaldson](https://github.com/WillDonaldson/Robotic-Snake/blob/master/_1D_robotic_snake/_1D_robotic_snake.ino).
in his program i have learned some important comand as "Servo myservo[10];" which he use to define 10 servomotors.
this command can simplify a lot of work as in a loop we can change servo by using a variable.

Also the movement that i wanted to replicate is on his programe with the fonction named slitther.
I have noticed the use of a mathematical formula "myServos[j].write(90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift));"
which does looks alike the one of an progressive plane wave.

actually the program fit with what we wanted so we have tested it with some pieces of the snake that we already had. 
![test 1](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/first_test2.jpg)
 which gave us this first result:[first_test](https://youtu.be/3seGkPpCPjw).
here the movement do not look normal because the snake was not initialise before we started the program.
So we know for the next time that while whe assemble the snake all the servomotors must be initialise with an 90° angle.

for the next session i will have to study deeper the program to make a test on a bigger snake.