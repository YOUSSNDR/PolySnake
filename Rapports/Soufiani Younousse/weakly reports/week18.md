## <p align=center> Session 21
<ins>11/04</ins>

Today, we work on the python programm to recognise arrows thanks to a camera.
This program will allow the raspberry to choose the direction by reading the arrow.
For this program we will be using the cv2 library.
As i have never used this library before i will have to learn.
For that i searched to see if someone had ever tried making the same programm, i found a discussion on stackoverflow on [How to detect different types of arrows in image?](https://stackoverflow.com/questions/66718462/how-to-detect-different-types-of-arrows-in-image)
from there i have tried two programs.
They both work with the same principle, reading the contour to find out if it matches with an arrow shape.

The first i have tried was the one of stateMachine (the first one who answerd) howeveras i still don't master this library i could not make this work.
There is the program: [cameraprogram1]()
I might come back on this one ones i have learned enough to understand the library.

The second program is from Prefect (another person who answered) this one i was able to make it work.
Here is the program: [cameraprogram2]()
For the test i use images found on the forum which are:
This one ![image1]()

And this one ![image2]()

The program worked perfectly with the first image ![img1recpg2]()

But had troubles recognising all the arrows on the second image ![img2recpg2]()

I have also tried getting help from chatGPT which end up with a working programm however less efficient than the other one.
The programm used is this one: [cameraprogramchatgpt]()
![img2recpgchatgpt]()

I will continue working on the program, Nino (a coworker) gave me a programm to try.
I will next try to test the programm and see if i can inprove it.
Guillaume (an other coworker) advise me to try to fill the arrows with easily recognisable colors for the program to detect it easier.
I will see all that.

For this session i have also took an arduino nano, which will carry the ultrasound sensor program.
I had first to weld the pin to it.

Welding session: ![welding session]()

For the programm testing part i will have to do that at home.