## Algorithmie

Pour notre projet nous avons pour l'instant deux principaux programmes utiles à notre Robots:
- l'un nous permet d'imiter les ondulations des serpents "mouvement2"
- l'autre nous permet d'utiliser le moteur "moteurs2"

### moteur2
Ce programme est assez simple il nous permettra de faire avancer ou reculer le robot, pour cela on done la direction (marche avant/arrière) et une vitesse voulue sous forme d'une valeur analogique.
voici un test: [wheels_test](https://drive.google.com/file/d/1kCXxd9m7_tPdRNpz16n7oTgrz3TyLUi4/view?usp=share_link)

### mouvement2
Ce programme est un peu plus complexe, il agit sur les différents servos moteur et leur donne des angles à atteindre, ces angles sont déterminé a partir d'une fonction sinusoïdale ce qui nous permet de voir une ondulation. aussi cette fonction sinuisoïdale nous permet de controler différent éléments:
- l'amplitude du mouvement 
- la vitesse de propagation de l'onde
- la longueur d'onde.
tout ça pour donner un mouvement plus ou moins réaliste au robot.

voici un test ou on a une modification de l'amplitude, une modification de la vitesse et l'utilisation d'un décallage pour changer de direction:
[test_ondulation1](https://drive.google.com/file/d/18OSwVxILO8t3YWNuw0CFthk3nBTT0Grp/view?usp=share_link)
[test2_ondulation](https://drive.google.com/file/d/18mUrjYc68gUuUbowsBK2COEysheR3PN-/view?usp=share_link)