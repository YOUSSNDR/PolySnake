
### Need to study the wheels
[how snake skin work](https://www.pnas.org/doi/10.1073/pnas.0812533106)

### Snake deplacement
- read a distance:(we might use an arduino nano for that)
    - if to short:
        - stop the slither motion
        - look at the obstacle
        - activate the camera
        - take the order
    - else:
    - continue the slither motion 

#### For that we need :
- arduino nano card
- arduino uno card 
- raspberry zero W card

#### How will they work

The arduino nano will take the distances continuously and advert the raspberry zero W when the limit distance is reached

The raspberry zero w card will be used when the limit distance is reach, it will take picture of the obstacle to know which path it should take.

The arduino Uno card will handle the slither movment, will receive order to stop when the limit distance is reached (may ask the snake to get on line). Will receive order from the raspberry zero W to know which path it should follow.

### programm part

#### Arduino

nano:
- take the distance

Uno:
- slither motion
- cases depending on the python programme

#### Python
receive the distance from arduino nano, if distance too short send value to arduino Uno (to stop the slithering motion), then take a picture and read the information. 

### Etapes
#### 1) slither program for displacement arduino uno (servos)
- make a program which mimic the snake displacement

#### 2) ultra sound sensor program arduino nano 
- make a program to take the distances
- see how we will connect this arduino

#### 3) communication program raspberry pi zero W
- send message from arduino nano to raspberry pi
- treat the received datas
- send message to the arduino uno

#### 4) program traitement d'image raspberry pi zero W (Camera V2)
- 