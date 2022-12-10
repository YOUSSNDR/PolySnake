## <p align=center> Session 2
<ins>18/10</ins>

[docs about the servomotor](https://fr.aliexpress.com/item/4000538643378.html?spm=a2g0o.productlist.0.0.153e77cbeRq38s&algo_pvid=f97120ce-80fe-4de0-9400-19d6e2d7d48e&algo_exp_id=f97120ce-80fe-4de0-9400-19d6e2d7d48e-37&pdp_ext_f=%7B%22sku_id%22%3A%2210000002764012600%22%7D&pdp_npi=2%40dis%21EUR%2124.62%2110.36%21%21%21%21%21%402100bddf16660742684322015e0f70%2110000002764012600%21sea&curPageLogUid=97oB1ft9vDh0)

i tried to find the issues by controlling the servomotors with a potentiometer and with the help of the Teacher, two source of problem were found:
- The système did not had enough courant to run properly, to fix that we will go from 400A to 850A for each servomotors.
- the servomotor had some troubles to rotate some times, we have to create some loop to avoid asking him an angle to big with not enough time.
the [program test1](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test1/test1.ino) have been improve to use the potentiometer

![image du test2](https://github.com/YOUSSNDR/PolySnake/blob/9571004a612a2b0bd469808a852043d67043e269/Rapports/Soufiani%20Younousse/images%20younousse/exp2.jpg)

And so we can return to the test witheout potentiometer this time we use an other program. [program test2](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test2/test2.ino)

in it we use directly the microseconds to move the servomotors because the angle are not precise in degrees directly.

The issue look to come from the library use, it might consider 270° which is the max angle of our servomotor for 180° which is the max angle for the sevomotors often use with this library.
  
I will have to check this for the next time.

