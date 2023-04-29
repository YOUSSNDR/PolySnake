## <p align=center> Session 22
<ins>25/04</ins>

The work done this session can be split in two part:

### Testing part
We have strated the session by trying the [slithering program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/programmes/servomoteurs/D%C3%A9placement/snakewalkV5.0.0/snakewalkV5.0.0.ino) with the snake and his new connections done by Audric (my coworker).
It did not worked quite well, so we decided to use a [test program](https://github.com/YOUSSNDR/PolySnake/blob/ad8bc102a174c1b50114d60de3b588967cde8104/programmes/test/FKGXWP0K16PF6PV/FKGXWP0K16PF6PV.ino) on each servomotor one by one to see where does the problem come from.
We found out that the two servomotors had there connectic therefore they where both receiving two different orders at the same time.

### Arrow detection program
Before the holidays Nino gave me a program to test ([Nino's program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/programmes/Cam%C3%A9ra/image%20recognition%204%20(Nino)/testarrowrec4.py))
The program did worked but not exactly as i wanted,
as it detect not only the arrows but also all other contour.
![imgpgNino](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/Rapports/Soufiani%20Younousse/images%20younousse/image1%20recognition%20program4.1.jpg)

So i have started making my own program using pieces of all the fourth programs i have.
for now [my program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/programmes/Cam%C3%A9ra/image%20recognition%205%20(youss)/testarrowrec5.py) use the preprocess of the [second program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/programmes/Cam%C3%A9ra/image%20recognition%202/testarrowrec2.py) which make it easier to find the contour.

we next go through all the contour and take the medium color inside it thanks to the 'cv2.mean' command.

for now it only detect contour and give the medium color inside it.
there is what it looks like: ![imgmyprgm](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/Rapports/Soufiani%20Younousse/images%20younousse/myprogram1.2.jpg)

We will next have to upgrade the program to detect only arrow shapes in the image and among them only the one with a red color.

Ps: i have already upgrade the programm here you can find [my second program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/programmes/Cam%C3%A9ra/image%20recognition%205%20(youss)/testarrowrec5.2.py) which i will continue to upgrade till next report where i will also explain the new features.
here are images of the second program: ![img my second program](https://github.com/YOUSSNDR/PolySnake/blob/dbf0446f182a6393fc1b76dd6d8bf0762ccefc0e/Rapports/Soufiani%20Younousse/images%20younousse/myprogram2.2.jpg)