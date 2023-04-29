## <p align=center> Session 22
<ins>25/04</ins>

The work done this session can be split in two part:

### Testing part
We have strated the session by trying the [slithering program]() with the snake and the new connections done by Audric (my coworker).
It did not worked quite well, so we decided to use a [test program]() on each servomotor one by one to see where does the problem come from.
We found out that the two servomotors had there connectic therefore they where both receiving two different orders at the same time.

### Arrow detection program
Before the holidays Nino gave me a program to test.
The program did worked but not exactly as i entneded,
the program detect not only the arrow but all other contour.
![imgpgNino]()

So i have started making my own program using pieces of all the fourth programs i have.
for now [my program]() use the preprocess of the [second program]() which make it easier to find the contour.

we next go through all the contour and take the medium color inside it thanks to the 'cv2.mean' command.

for now it only detect contour and give the medium color inside it.
there is what it looks like: ![imgmyprgm]()

We will next have to upgrade the program to detect only arrow shapes in the image and among them only the one with a red color.

Ps: i have already upgrade the programm here you can find [my second program]() which i will continue to upgrade till next report where i will also explain the new features.
here are images of the second program ![img my second program]()