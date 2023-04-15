import serial
import time

arduino1 = serial.Serial(port='COM15', baudrate=115200, timeout=.1)


def write(x):
    arduino1.write(bytes(x, 'utf-8'))
    return x

while True:
    for i in range(0,30,1):
        write(str(i))
        print(i)
        time.sleep(1)
