## <p align=center> Session 13
<ins>07/02</ins>

We have talked about the components we should use in order for the snake to move.
For that we have study a [video](https://www.instructables.com/Snake-Robot-1/) of a snake looking a bit like our but with multiple wheels,
what is interesting here is that apparently not anny of the wheels are motorised insted the person use the sinusoïdal mouvement which allow the snake thanks to the wheels to go forward.
We are planing on testing that as soon as we receive the wheels.

Also for all the image recognition part i will have to use a Raspberry pi Zero 1 W card which will work like a little compteur and will allow us to make an autonomous robot. In order to use the card we will need multiple component that we will have to order. After research we end up with [this list of component that we need to order](https://github.com/YOUSSNDR/PolySnake/blob/b258c2d82ef8cb8ddd8b45ca130dc0260bcdb722/Achats/Achats.md).
Among them i have put a Raspberry pi zero 2 W witch should be an improved version of the zero 1 W.
Also i have continue my work on the [Computer Vision With Arduino | 2 Hour Course | OpenCV Python](https://youtu.be/mfiRJ1qgToc).
We can now:
- command the program to stop or continue the slither motion witheout reuploading it every time
- connect the arduino board to python 
- make a communication betwin python and arduino

We have now this [arduino program](https://github.com/YOUSSNDR/PolySnake/blob/b258c2d82ef8cb8ddd8b45ca130dc0260bcdb722/programmes/servomoteurs/D%C3%A9placement/snakewalkpython-arduino/snakewalkpython-arduino.ino) which can work with this [python program](https://github.com/YOUSSNDR/PolySnake/blob/b258c2d82ef8cb8ddd8b45ca130dc0260bcdb722/programmes/Arduinocv/Output/snakewalk..py).

here the value sent with arduino.sendData() in python put the snake in straightline if the value is 1 or continue the motion if the value is 0.

Now we will have to study the image recognition part and reproduce everything in the Raspberry pi.