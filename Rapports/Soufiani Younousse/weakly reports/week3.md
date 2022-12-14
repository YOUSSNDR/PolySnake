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

then using an upgrade of the program test2 [program test2_2](https://github.com/YOUSSNDR/PolySnake/blob/main/programmes/servomoteurs/test2/test2_2.ino) i have verified the minimum and maximum angles. an obtained this ![Rotation du servo](https://github.com/YOUSSNDR/PolySnake/blob/d8df9ac458cd2a9e06b5fb9730dac2725eff6cc4/Rapports/Soufiani%20Younousse/images%20younousse/rotation%20du%20servo.png)

which give us a <span style="clor:red">coefficient of 2/3</span> betwin the asked angle and the obtain angle which give us those important datas ![donées importantes](https://github.com/YOUSSNDR/PolySnake/blob/d8df9ac458cd2a9e06b5fb9730dac2725eff6cc4/Rapports/Soufiani%20Younousse/images%20younousse/don%C3%A9es%20importantes.png)

i have also been able to try two servomotors moving at the same time with the create program [snake walk](https://github.com/YOUSSNDR/PolySnake/blob/d8df9ac458cd2a9e06b5fb9730dac2725eff6cc4/programmes/servomoteurs/D%C3%A9placement/snake%20walk/snake%20walk.ino),
which is only a test for now which will be upgrade next to mimic the snake ondulation.