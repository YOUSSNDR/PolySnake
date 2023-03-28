## <p align=center> Session 18
<ins>21/03</ins>

In this session we have mostly tried to fix an issue on the snake.

So to start the session we wanted to try our program again to see what we could improve next, either on the snake and in the program.
But as i ve started uploading the program in the arduino we have got an error. ![error](https://github.com/YOUSSNDR/PolySnake/blob/3ed7231236f0d38b31f6915a813f5366cb5431b6/Rapports/Soufiani%20Younousse/images%20younousse/arduino%20error1.jpg)

after searching a bit i ve found out that some of my libraries where missing (Servo.h and cvzone.h) so i had to get them back (or at least Servo.h) to run the test.
after the installation there where no more problem with the libraries.
However in the test the snake was not totally working as it was last week.
A servomotor had troubles to turn :
![bugged snake](https://github.com/YOUSSNDR/PolySnake/blob/3ed7231236f0d38b31f6915a813f5366cb5431b6/Rapports/Soufiani%20Younousse/images%20younousse/bugged%20snake.jpg)

The probleme looked a bit as the one we had at the start when the servomotor where struggling to reach an asked position.
To fix this issue the solution were to:
- give it enough current to run properly each servomotor.
- if that was not the solution then it meant that the servomotor did not had enough time to reach the asked position.

But here the problem did not came from those two assumption.
Audric (My coworker) Thought that maybe it was the servomotor wich did not work, So we have tried to move the servomotor separetly with a more simple program.
[servo test](https://drive.google.com/file/d/1sBgIdRgADSiTIa0Xv_KnTtk07N9oUKNa/view?usp=share_link)
And the servomotor did work, the last thing left was to verify the program.


Thank to Guillaume we have found this issue:
![issue](https://github.com/YOUSSNDR/PolySnake/blob/3ed7231236f0d38b31f6915a813f5366cb5431b6/Rapports/Soufiani%20Younousse/images%20younousse/issue.jpg)

One pin was receiving two different orders, I probably forgot to change the servo 8 pin last time i have used it and as i did not use it in the main program i thought that it would not affect the rest of the snake.
After fixing that, the snake finally worked as it should have:
[fixed snake](https://drive.google.com/file/d/1Kew2NjVZXMZn-QXQE4DfPmHUft6UFAHi/view?usp=share_link)