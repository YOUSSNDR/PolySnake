## <p align=center> Session 7
<ins>09/12</ins>

We began the session by cleaning the new 3D pieces we had as we needed them for the test.
![cleaning time](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/cleaning%20session.jpg) 

After cleaning all the pieces we could now test the snake.
- First i prepared the programs needed while my coworker was adding the servomotors into the pieces.
- then i pluged all the servomotors so we could initialise all se servomotors at an 90° angle before attaching them (to have all the sermotors forming a straight line in the initialisation).
with [line](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/ligne/ligne.ino)
![snake](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/full_snaketest2.jpg)
- And so we could start the testing with [servos_testing](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/servos_testing/servos_testing.ino).
which are some simple order. And there is the result [Test servos](https://youtu.be/MFZg65ag1Ys).

Next test was the "snake_walk" (snake ondulation).
for it we used this program [snake walkV5](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/snakewalkV5.0.0/snakewalkV5.0.0.ino).
And here is the result [Second test](https://youtu.be/CUl1Hz0VQxA)

the program use different variable allowing us to modify the mouvement in deffrent way:
- modify the offset allows the snake to in his moves tend to go in a direction (>0 right, <0 left).
- modify the amplitude will modify the height of the sinusoïd top.
- modify speed will increase or decrease the speed of the propagating waves.
- and modify wavelenght will make the waves more or less large.
as it use a formula which looks alike with  the one defining a progressive wave propagating on a 2D plan.

We will verify this next time.
But the main goal for the next session will be to learn how to controle an arduino device with an app.
And for another time we will try to adapt some of the program on a class. 