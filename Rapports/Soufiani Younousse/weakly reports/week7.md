## <p align=center> Session 8
<ins>14/12</ins>

To start this new session we add one more module to the snake 
and fix some screw issues on the snake (some screw were to long and so were rubbing the snake).
![seven_module_snake]()
Change of plan from what we wanted to do last week.
as with the control of his ondulation the snake can turn right and left we might use that to make it turn on wheels.
but for that we need to work the transition.
Two types of transition are to work on:
    - to make the snake form a line 
    - to turn

To line up:
    the snake will have to lose some amplitude if the path he is following is getting finer. in order to do that we use the slither function and drop the amplitude.
    But as the amplitude drops the movment looks slower so we also need to control the speed. After several test it seems that increasing the spead of 1°/s for every drop of 5 cm in amplitude give it a much better look.

To turn:
    We will need the snake to turn, for that we also use the slither function. when ask to turn the snake make the turn but to fast (it could break somthing). so we use a while loop and a delay fuction toslow down the turn.

there is a test where the turn is to strong [test turn and amplitude 1](https://drive.google.com/file/d/18OSwVxILO8t3YWNuw0CFthk3nBTT0Grp/view?usp=share_link)

there is the second test where the the amplitude and the turn where controlled [test turn and amplitude 2](https://youtu.be/qZ7Id3EbTI4)