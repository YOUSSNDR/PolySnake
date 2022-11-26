## <p align=center> Session 5
<ins>26/11</ins>
We have received sole servomotors with 180 degrees angle which is enough for our snake and limit the risks of braking the snake by going to far on a test.

Then there was a test  of the program [snake_walkV2](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/snake%20walk/snake%20walk%20V2/snake%20walk%20V2.ino) after correcting all the little mistakes made before. 
multiple issues appeared:
    - first the program working on four steps had only two of them working, this was because of the conditions step 1 worked because of the initialisation and then step 3 always had the conditions to work.
    - The servomotors decided not to work "again", but this time not because of lack of intensity and voltage drop. I have changed the cables but still nothing moved even with some simple test programs [test3](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test3/test3.ino) and [test4](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test4/test4.ino). with the help of a teacher it finally worked, i m still not sure of why it did not worked before. the servomotors starts worfking rigth after the mulitmeter have been plug, for the teacher it is a fake contacte somwere (but i have changed the wires before ) after that they was some litle bug but they where working. i will reduce next time the number of wires to limit the risks (i will need some longer ones).

After that i have tried again the [snake_walkV2](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/snake%20walk/snake%20walk%20V2/snake%20walk%20V2.ino). but still nothing moved they where some other mistakes in it :
        - the program was still making simultaneously the two same steps because the end condition of the two steps where matching each others.
        - even if the steps where passed still not any movement where made.

I decided after that to make a new program as this one already had multiple default at his creation as seen week4 (already a mess for three servomotors it would be even worse for eight ) and another program would be needed to control more servomotors. It will be finished for or during next session and will be named [snake_WalkV3]()