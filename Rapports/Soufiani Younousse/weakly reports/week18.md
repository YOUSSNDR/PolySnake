## <p align=center> Session 21
<ins>11/04</ins>

Today, we work on the python program to recognise arrows thanks to a camera.
This program will allow the raspberry to choose the direction by reading an arrow.

For this program we will be using the cv2 library.
As i have never used this library before i will have to learn.
For that i searched to see if someone had ever tried making the same program before, i have found a discussion on stackoverflow on [How to detect different types of arrows in image?](https://stackoverflow.com/questions/66718462/how-to-detect-different-types-of-arrows-in-image)
and from there i have tried two programs.
They both work with the same principle, which is reading the contour to find out if it matches with the one of an arrow.

The first one i have tried was the one of stateMachine (the first one who answerd) however as i still don't master this library i could not make this one work.  
There is the program: [cameraprogram1](https://github.com/YOUSSNDR/PolySnake/blob/695c97967ed71693cd3f5189af5707c93969878c/programmes/Cam%C3%A9ra/image%20recognition%201/testimgrec1.py)  
I might come back on this one later ones i have learned enough to understand the library.

The second program comes from Prefect (another person who answered) this one i was able to make it work.  
Here is the program: [cameraprogram2](https://github.com/YOUSSNDR/PolySnake/blob/695c97967ed71693cd3f5189af5707c93969878c/programmes/Cam%C3%A9ra/image%20recognition%202/testarrowrec2.py)

For the test i use images found on the forum which are:  
This one ![image1](https://github.com/YOUSSNDR/PolySnake/blob/695c97967ed71693cd3f5189af5707c93969878c/programmes/Cam%C3%A9ra/image%20recognition%202/arrows.png)  
And this one ![image2](https://github.com/YOUSSNDR/PolySnake/blob/695c97967ed71693cd3f5189af5707c93969878c/programmes/Cam%C3%A9ra/image%20recognition%202/arrows2.png)

The program worked perfectly with the first image ![img1recpg2](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/image1%20recognition%20program2.jpg)  
But had troubles recognising all the arrows on the second image ![img2recpg2](https://github.com/YOUSSNDR/PolySnake/blob/695c97967ed71693cd3f5189af5707c93969878c/Rapports/Soufiani%20Younousse/images%20younousse/image2%20recognition%20program2.jpg)

I have also tried getting help from chatGPT which end up with a working programm however less efficient than the other one.
The programm used is this one: [cameraprogramchatgpt]()
![img2recpgchatgpt](https://github.com/YOUSSNDR/PolySnake/blob/695c97967ed71693cd3f5189af5707c93969878c/Rapports/Soufiani%20Younousse/images%20younousse/chat%20gpt%20program%20test.jpg)

I will continue working on the program, Nino (a coworker) gave me a programm to try.
I will see if i can inprove it for the final use.
Guillaume (an other coworker) advise me to try to fill the arrows with easily recognisable colors for the program to detect it easier.
I will see all that.

For this session i have also took an arduino nano, which will carry the ultrasound sensor program.
I had first to weld the pin to it.

Welding session: ![welding session](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/welding%20session.jpg)

For the programm testing part i will have to do that at home.