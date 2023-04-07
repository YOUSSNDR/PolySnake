## Python program

we will be using the library Serial(from pyserial) 

#### Arduino serial
we will be using two arduino an Uno and a Nano
the serial.Serial allow us to connect the port  to the python program

#### def read
here we read de value printed by the arduino nano

#### def write
here we send a value to the arduino Uno

#### def image processing
here we have to read an image in order to find out which path we need to take

### Main program
we use an infinite loop where we:
- read the arduino nano
- if the value is above 8 cm:
    - send nothing to UNO(keep going forward) 
- else if the value is 8 or under:
    - send value to UNO (stop the movment)
    - start the image processing protocol
    - send a new value to the UNO (chose a path)

