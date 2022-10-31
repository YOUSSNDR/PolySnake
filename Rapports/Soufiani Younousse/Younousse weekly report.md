
# <p align=center> <ins>POLYSNAKE</ins>    
# <p align=center> <ins>REPORTS</ins>

Soufiani

Younousse

<ins>2022/2023</ins>

## <p align=center> Session 1
<ins> 14/10 <ins>

I have started to schematizes some simple situation to visualize how the program will work.
Situation 1(left turn):
![how it works](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/snake1.png?raw=true)  
![how it works2](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/snake2.png?raw=true)
![how it works3](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/snake3.png?raw=true)
![how it works4](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/snake4.png?raw=true)


study of the servomotor and the Arduino library needed to use it.
I start by moving one servomotors then two of them.
There is the program used:
[program test1](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test1/test1.ino)
![image du test1](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/exp1.jpg?raw=true)

They are troubles with the servomotors:
- some unwanted movement
- trouble to reach the ask angle
- issues to synchronize the servomotors together
Those issues may come from the fact that those servomotors unlike the usual I use goes to 270 degrees. 
I will have to gather more data about them.

## <p align=center> Session 2
<ins>18/10</ins>

[docs about the servomotor](https://fr.aliexpress.com/item/4000538643378.html?spm=a2g0o.productlist.0.0.153e77cbeRq38s&algo_pvid=f97120ce-80fe-4de0-9400-19d6e2d7d48e&algo_exp_id=f97120ce-80fe-4de0-9400-19d6e2d7d48e-37&pdp_ext_f=%7B%22sku_id%22%3A%2210000002764012600%22%7D&pdp_npi=2%40dis%21EUR%2124.62%2110.36%21%21%21%21%21%402100bddf16660742684322015e0f70%2110000002764012600%21sea&curPageLogUid=97oB1ft9vDh0)

i tried to find the issues by controlling the servomotors with a potentiometer and with the help of the Teacher, two source of problem were found:
- The système did not had enough courant to run properly, to fix that we will go from 400A to 850A for each servomotors.
- the servomotor had some troubles to rotate some times, we have to create some loop to avoid asking him an angle to big with not enough time.
the [program test1](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test1/test1.ino) have been improve to use the potentiometer

![image du test2](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/exp2.jpg?raw=true)

And so we can return to the test witheout potentiometer this time we use an other program. [program test2](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test2/test2.ino)

in it we use directly the microseconds to move the servomotors because the angle are not precise in degrees directly.

The issue look to come from the library use, it might consider 270° which is the max angle of our servomotor for 180° which is the max angle for the sevomotors often use with this library.
  
I will have to check this for the next time.

## <p align=center> Session 3
<ins>28/10</ins>

### <ins>Homework</ins>

I had to verify the angle at home in order to do that i had plan to :
- first ask the servomotors for an 90° angle to see if it shows the center
- then ask him an angle of 180° to see how the library work 

However being at home i did not had acces to an efficient generator so the servomotor was strugling to get to the asked angle.

My solution was to create a loop asking him to move angle by angle while letting him enough time to reach each one of those.
to fond the needed time i have used the [docs about the servomotor](https://fr.aliexpress.com/item/4000538643378.html?spm=a2g0o.productlist.0.0.153e77cbeRq38s&algo_pvid=f97120ce-80fe-4de0-9400-19d6e2d7d48e&algo_exp_id=f97120ce-80fe-4de0-9400-19d6e2d7d48e-37&pdp_ext_f=%7B%22sku_id%22%3A%2210000002764012600%22%7D&pdp_npi=2%40dis%21EUR%2124.62%2110.36%21%21%21%21%21%402100bddf16660742684322015e0f70%2110000002764012600%21sea&curPageLogUid=97oB1ft9vDh0) which give the rotational speed in both direction and chosed there the biggest time.
which left me with 0.32s/60° convert that giving me a little less than <span style="color:red">0.006s/1°</span>.

That left me with this code:
 [program test angles](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test_angles/test_angles2/test_angles2.ino)
 the program worked but still strugle at the initialisation.

### <ins>ClassWork</ins>

I have started by some simple test to move one servo motor but it was strugling to move even with a generator.
The reason was a missunderstood of myself the generator only limitate to some intensity and the servomotor take the intensity it need so  i had to go to 1.2A on the generator even knowing that the [docs about the servomotor](https://fr.aliexpress.com/item/4000538643378.html?spm=a2g0o.productlist.0.0.153e77cbeRq38s&algo_pvid=f97120ce-80fe-4de0-9400-19d6e2d7d48e&algo_exp_id=f97120ce-80fe-4de0-9400-19d6e2d7d48e-37&pdp_ext_f=%7B%22sku_id%22%3A%2210000002764012600%22%7D&pdp_npi=2%40dis%21EUR%2124.62%2110.36%21%21%21%21%21%402100bddf16660742684322015e0f70%2110000002764012600%21sea&curPageLogUid=97oB1ft9vDh0) ask for 0.2A.

then using an upgrade of the program test2 [program test2_2](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test2/test2_2.ino) i have verified the minimum and maximum angles. an obtained this ![Rotation du servo](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/rotation%20du%20servo.png?raw=true)

which give us a <span style="clor:red">coefficient of 2/3</span> betwin the asked angle and the obtain angle which give us those important datas ![donées importantes](https://github.com/YOUSSNDR/PolySnake/blob/main/Rapports/images%20younousse/don%C3%A9es%20importantes.png?raw=true)

i have also been able to try two servomotors moving at the same time with the create program [snake walk](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/snake%20walk/snake%20walk.ino),
which is only a test for now which will be upgrade next to mimic the snake ondulation.