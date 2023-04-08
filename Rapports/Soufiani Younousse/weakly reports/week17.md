## <p align=center> Session 20
<ins>04/04</ins>

For this session i have started by trying to find a way to keep the snake head looking at the target by assuming that in any time the sum of the angle made by all the servo motor thanks to the formula use would be constant and equal to zero, how ever i could not demonstrate it at the moment. As it is not the most important part for now i have stopped working on that.

I then switched on a main issue still left, the distance perception. To fix this issue i have choose to add an ultrasound sensor which we would use with an arduino nano. Using the arduino nano may cost more energy but thank to it we avoid Timers issues and also we will be able to read information while the snake will be moving at any time.

Now that i had the idea, i had to find a new way to make communicate the different arduino with the raspberry. I wanted to use the Opencv library but i have finally changed to the pyserial library after asking to Guillaume (a coworker).

Now that i had all the pieces of the final programm, i needed to see how they would all work together.
For that i have created markdown document explaining which program would be use where and what for. here it is -->
[programs explaination](https://github.com/YOUSSNDR/PolySnake/blob/1201f99eacff5840884c5b49c1f553cf679b7878/programmes/snake/snake.md).

All that left us with aproximatly 4 programm to create or upgrade:
- [snakewalk](https://github.com/YOUSSNDR/PolySnake/blob/1201f99eacff5840884c5b49c1f553cf679b7878/programmes/snake/snake1/arduino%20uno/snake_walk_condition/snake_walk_condition.ino) (from arduino) which need to be upgrade and adapt.
- [ultrasound sensor](https://github.com/YOUSSNDR/PolySnake/blob/1201f99eacff5840884c5b49c1f553cf679b7878/programmes/snake/snake1/arduino%20nano/distance/distance.ino) (from arduino) which also need to be upgrade and adapt.
- [communication](https://github.com/YOUSSNDR/PolySnake/blob/1201f99eacff5840884c5b49c1f553cf679b7878/programmes/snake/snake1/raspberry/python1.py) (in python) which need to be upgrade.
- and finally the camera detection part (in python) that we need to create and add in the [communication](https://github.com/YOUSSNDR/PolySnake/blob/1201f99eacff5840884c5b49c1f553cf679b7878/programmes/snake/snake1/raspberry/python1.py) program.

Also to make the communication program clearer there is a [readme](https://github.com/YOUSSNDR/PolySnake/blob/1201f99eacff5840884c5b49c1f553cf679b7878/programmes/snake/snake1/raspberry/readme.md) explaining all the function in it.