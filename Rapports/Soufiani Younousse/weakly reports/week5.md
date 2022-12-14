## <p align=center> Session 5
<ins>26/11</ins>

We have received some servomotors with 180 degrees angle which is enough for our snake and limit the risks of braking the snake by going to far on a test.

Then there was a test  of the program [snake_walkV2](https://github.com/YOUSSNDR/PolySnake/blob/d8df9ac458cd2a9e06b5fb9730dac2725eff6cc4/programmes/servomoteurs/D%C3%A9placement/snake%20walk%20V2/snake%20walk%20V2.ino) after correcting all the little mistakes made before. 
multiple issues appeared:
    - first the program which normally work in four steps had only two of them working, this was because of the conditions. Step 1 worked because of the initialisation and then step 3 always had the conditions to work.
    - The servomotors decided not to work "again", but this time not because of lack of intensity and voltage drop. I have changed the wires but still nothing moved even with some simple test programs [test3](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test3/test3.ino) and [test4](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test4/test4.ino). with the help of a teacher it finally worked, i am still not sure of why it did not worked before. the servomotors starts working rigth after the mulitmeter have been plug, for the teacher it is a fake contacte somwere (but i have changed the wires before) after that they where some litle bug but they where working. i will reduce next time the number of wires to limit the risks of fake contact (i will need some longer wires).

After that i have tried again the [snake_walkV2](https://github.com/YOUSSNDR/PolySnake/blob/d8df9ac458cd2a9e06b5fb9730dac2725eff6cc4/programmes/servomoteurs/D%C3%A9placement/snake%20walk%20V2/snake%20walk%20V2.ino). but still nothing moved they where some other mistakes in it :
        - the program was still making simultaneously the two same steps because the end condition of the two steps where matching each others.
        - even if the steps where passed still not any movement where made.

I decided after that to make a new program as this one already had multiple default at his creation as seen on week4 (already difficult with three servomotors it would be even worse with eight ) and another program would be needed to control more servomotors. It will be finished for or during next session and will be named [snake_WalkV3](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/D%C3%A9placement/snake%20walkV3/snake%20walkV3.ino).

A sheet explaining how i want to make it work is available here on [snake_walkV3_sheet](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/Soufiani%20Younousse/images%20younousse/test%20angles%20servos.pdf).
The program will use a list containing all the angle in the order they need to be ran and each servomotors will follow the list whith a shift depending on their position.