## <p align=center> Session 14
<ins>14/02</ins>

- Work on the program:
    The goal was to modify the snake movement depending on the value send by python
    for that i've: 
    - listed the movement i wanted 
    - made a logical table out of them
    and so i was left with that : ![table_logique1](https://github.com/YOUSSNDR/PolySnake/blob/597d010115ae88e9abda92383aeb4ddf81eb186f/Rapports/Soufiani%20Younousse/images%20younousse/table%20logique1.jpg) ![table_logique2](https://github.com/YOUSSNDR/PolySnake/blob/15777205acda2ff8ac74c616b032026ad5cf631f/Rapports/Soufiani%20Younousse/images%20younousse/table%20logique2.jpg)
    (Maybe a little bit to much for the task) I have now all the movement i want to use and a number link to them.
    they are 9 cases:
        - line (snake in line)
        - slither (the snake go forward)
        - slither right (the snake take a right turn)
        - slither left (the snake take a left turn)
        - stop line (the snake get in line and wait)
        - stop left (the snake get in position to turn left then stop) 
        - stop right (the snake get in position to turn right then stop)
        - stop (the snake stop his mouvement)
             mouvement that we will later reduce to four:
        - line (snake in line)
        - slither (the snake go forward)
        - slither right (the snake take a right turn)
        - slither left (the snake take a left turn)
        - stop (the snake stop his mouvement)
    
    So i've tried this in a test program
    where all the case choice was made in the void loop but i have seen some issue with the slither loop in it, so i tried a new program [snakewalk-case2](https://github.com/YOUSSNDR/PolySnake/blob/15777205acda2ff8ac74c616b032026ad5cf631f/programmes/test/test%20mouvement/snakewalk-case2/snakewalk-case2.ino)
    here the case are directly in the slither loop but still they will be trouble in the program.
    I have to modify the program to be able to cut the slither fonction anywhere this would allow the stop case to work.
    i will try that on the next program and also keep the four cases to simplify it.
