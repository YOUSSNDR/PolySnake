## <p align=center> Session 17
<ins>13/03</ins>

For this Session we made a lot of test and verify a theorie we had.

### Cleaning Time:
So first we start the session by cleaning the new pieces ![cleaning session]() 

Those new pieces can be mounted on wheels which will allows us to make the first tests.

### tests:
The idea we had was that more of the work on the slithering motion was made by the friction.
And as it was pretty complicated to make a snake skin we chosed Rubber wheels (as they will roll if the force that they receive is parallel to them and be block more and more by friction as the force get perpendicular to them).
after assembling the snake and initialising the servomotors it looked like that: ![snake on wheels]()

then we used those [different program](https://github.com/YOUSSNDR/PolySnake/tree/main/programmes/Classes/mouvement) to make it move:
the first test worked but with some troubles, as the snake make movement that are too big we have to much friction.
However we can modify parameters on the snake movement in the program. After multiple test we have understood that we needed to find an equilibrium betwin Amplitude and Wavelength (at some point to increase the the amplitude but avoid to much friction we needed to increase wavelengths which actually decrease the amplitude ).
we saved the characteristics which where working good togethers an offset of 3(to regulate a default either on the conception or in the initialisation which was making the snake going lightly to the right) an amplitude of 43, a speed and a wavelength of 2 (those measures have not equivalent with reality for now as the different characteristics change as we modify the pieces so we need to take mesurements to find the coeficient given in reality). the line of code looked like this in the code: 
slither(3,43,2,2)

here are some footage of the snake slithering thanks to the wheels:
[snake on wheels2 ](https://drive.google.com/file/d/16HxC7rm6nMEpBZPa2jUxAVyJ_MZUEDOj/view?usp=share_link), [snake on wheels3](https://drive.google.com/file/d/110NtvDqg1qCNGc-kb5Mu2t1d70bv_1B8/view?usp=share_link)

### Research:
To verify my belief i have looked for articles one of them made some good points ([the article](https://www.pnas.org/doi/10.1073/pnas.0812533106)).
I noted a couple sentences which where going with my thought:
- unlike most other terrestrial organisms of this size, body inertia is not central to slithering locomotion. Motion instead arises by the interaction of surface friction and internal body forces.
- these scales provide the snake a preferred direction of sliding on surfaces of sufficient roughness and compliance
- Another aspect that we have not considered is that snakes are likely able to dynamically change their frictional interactions with a surface by adjusting the attitude of their scales