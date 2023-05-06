import serial
import time

limit=15 # 15 cm distance where the snake stops to make a decision
arduinoNANO = serial.Serial(port='', baudrate=115200, timeout=.1)
arduinoUNO = serial.Serial(port='COM14', baudrate=9600, timeout=.1)

def read():
    data = arduinoNano.readline()
    return data
def write(x):
    arduinoUNO.write(bytes(x,'utf-8'))
##def write_read(x):
##    arduino1.write(bytes(x, 'utf-8'))
##    time.sleep(0.05)
##    data = arduino1.readline()
##    return data

def watch():



while True:
    # let s get first the distance value
    distance = read()
    if distance < limit:
        write(4) ## we stop the snake
        decision=watch()  ## start the image recognition protocol
        if decision==0:
            write(0)
        elif decision==1:
            write(1)
        elif decision==2:
            write(2)
        elif decision==3:
            write(3)
        else :
            write(4)
    ##num = input("Enter a number: ")
    ##value = write_read(num)
    ##print(value)