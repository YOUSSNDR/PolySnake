## <p align=center> Session 23
<ins>02/05</ins>


### Arrow deterction program
I have took the work from where i left last week.
Now i have three version of the arrow detection program. 
We will sart with the [second program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/programmes/Cam%C3%A9ra/image%20recognition%205%20(youss)/testarrowrec5.2.py) which can now get the position of the tip of the arrow and get the center of the rectangle which can contain the arrow in order to get the direction of the arrow.
![image pg2](https://github.com/YOUSSNDR/PolySnake/blob/2009bf68ff010cee0d42282d08546313a76a4bc5/Rapports/Soufiani%20Younousse/images%20younousse/myprogram2.3.jpg)

For the [third program](https://github.com/YOUSSNDR/PolySnake/blob/2009bf68ff010cee0d42282d08546313a76a4bc5/programmes/Cam%C3%A9ra/image%20recognition%205%20(youss)/testarrowrec5.3.py) program i have changed the way the program recognise color to be more efficient the program now check if the color hue value of the pixel at the center of the contour is in a range of 0 tO 5 OR above 170 to know if it is red. this methode is more efficient as even if the brightness change the HVR mode color can help recognise the color.

for the [fourth program](https://github.com/YOUSSNDR/PolySnake/blob/2009bf68ff010cee0d42282d08546313a76a4bc5/programmes/Cam%C3%A9ra/image%20recognition%205%20(youss)/testarrowrec5.4.py) it mostly a rearrangment of the third programm.
here we choose to first check the contour to see if it match the one of an arrow and then check the color to see if it is red.
![img prgm4](https://github.com/YOUSSNDR/PolySnake/blob/2009bf68ff010cee0d42282d08546313a76a4bc5/Rapports/Soufiani%20Younousse/images%20younousse/myprogram4.jpg)

i have stock all the program needed for the snake on a file [snake 2](https://github.com/YOUSSNDR/PolySnake/tree/main/programmes/snake/snake2.0)


We had later trouble using the arduino nano (it would not upload any program). It may be a problem from arduino.
I will have to create a python program for the ultrasound sensor. We will be using the raspberry to control it.