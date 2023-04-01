## <p align=center> Session 19
<ins>28/03</ins>

My goal this session was to modify the program to make it easier to use with a sensor. The issue we had with the program we currently use is that the main fonction allowing the slithering motion can not be interrupt before the end of a for loop incrementing from 0 to 360.
Which mean that the snake would have to finish his movement before changing direction (for exemple). However we want the snake to stop exactly when the order to stop is given.
Also at the end of the slithering movment the snake will stop if the function is not called again.
Here is the old programm (the test version): [snakewalkV5](https://github.com/YOUSSNDR/PolySnake/tree/main/programmes/servomoteurs/D%C3%A9placement/snakewalkV5.0.0)
there is what we whant to change: ![replaced sexion](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/arduino%20replaced%20sexion.jpg)

I have changed the for loop by a while loop depending on a boolean variable so that if the variable reurn false everything stop, else the motion never stop.

Here is the new programm: [snakewalk condition](https://github.com/YOUSSNDR/PolySnake/tree/main/programmes/servomoteurs/D%C3%A9placement/snake_walk_condition)
there are the modified lines: ![new lines]()

after test the new program work just as good as the old one:
[test new program]()

What we will do now is add a function to modify the values in the slither function to make it turn. And for that i will use the Opencv library which allow me to send datas from python to the arduino. I have made a couple test which did not worked the python program have trouble to connect with the card, i will have to fix that.

There is the last program (not ready yet):
[last prog cond 2](https://github.com/YOUSSNDR/PolySnake/tree/main/programmes/servomoteurs/D%C3%A9placement/snake_walk_condition2)