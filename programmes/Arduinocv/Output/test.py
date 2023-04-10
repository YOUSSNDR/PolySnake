import serial
import time

arduino1 = serial.Serial(port='COM15', baudrate=115200, timeout=.1)


def write_read(x):
    arduino1.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino1.readline()
    return data


while True:
    num = input("Enter a number: ")
    value = write_read(num)
    print(value)
