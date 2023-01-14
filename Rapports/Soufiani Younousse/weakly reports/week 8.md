## <p align=center> Session 10
<ins>13/01</ins>

### Holidays Work
for the holidays i have ask for some pieces to run some test by my own.
those pieces were:
- an arduino Sensor Shield V5.0
-  a MDD3A Motor Driver
- a DC 2 axes 5V motor
[wheels_and_MDD3A]!(https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/Rapports/Soufiani%20Younousse/images%20younousse/roue%20et%20MDD3A.jpg)

[card_and_Shield]!(https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/Rapports/Soufiani%20Younousse/images%20younousse/carte%20et%20Shield.jpg)

to run all that i had a 5V power supply.
thanks to the Shiel the connections were modify giving a much clean result. I had trouble using the power supply but i have been able to try a program allowing me to use a joystick to control a servomotor.
[joystic_control](https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/programmes/servomoteurs/test%20controle%20par%20analogue/test%20controle%20par%20analogue.ino)

### Algorithm course
On those course i worked on a program to detect obstacles.
My first idee was to use an ultrasound sensor to detect obstacles for therefore i took an old program i had and ad a function to move the head of the snake.

there is a photo of the ultrasound sensor working alone:
[Ultrasound_sensor]!(https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/Rapports/Soufiani%20Younousse/images%20younousse/capteur%20a%20ultrason1.jpg)
there is the program and a video of the snake analysing his surounding after the slither move:
[surrounding_detection](https://drive.google.com/file/d/1-J1L_gpx6d5yrn2LekHKFwAyNEZ4aanV/view?usp=share_link)

### course
We finally chose an other way for the snake to know when to make a turn, the idea is to use a rasbery pie camera to analyse the image of an arrow giving the direction the snake have to take.

So for this session i chose to work on the program to make the snake go forward or backward for that we use a DC 2 axes 5V motor, i came up with this program:
[Wheels_testprogram1](https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/programmes/Roues/premier%20test/premier%20test.ino)
there is what it looks like:
[heels_test1](https://drive.google.com/file/d/1kCXxd9m7_tPdRNpz16n7oTgrz3TyLUi4/view?usp=share_link)

but it seems that i can only make them turn at fool speed, so i tried another program to try control it:
[Wheels-testprogram2](https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/programmes/Roues/2nd%20test/2nd%20test.ino)

the program allow me to control the speed by raising the tension. We can see that the wheels start to turn at the analogic value of 50 which is around 1V. Nino advised me to use a PWM i will look for it for the next session.

As i was working on the motors my coworker which is working on the "skeleton" of the snake asked me about the max angle took by the snake in the slither move to avoid breaking the new pieces. I had to modify the program to giveme the answer:
[slither_test1](https://github.com/YOUSSNDR/PolySnake/blob/df2c1382a202e414176d68fe3e251ddcb0f33a08/programmes/test/test%20angle%20maxi/test%20angle%20maxi.ino)
So now we know that the max values taken is 120° and as our servomotors are settled on 90° we know that the max angle is 30°.
