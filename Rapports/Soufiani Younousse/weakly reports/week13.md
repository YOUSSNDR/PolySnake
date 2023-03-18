## <p align=center> Session 16
<ins>07/03</ins>
Work on the rasberri pi zero 1W:
the .conf had trouble to work.
after a restart i have found an error in the text of the ".conf" file, after fixing it the raspberrypi finally appeard with the others devices connected to my wifi point.
normally to use the ssh conection you need to use the command "ssh pi@raspberry" if it is on factory settings.
you will next have to enter the password witch is normally "raspberry".
after that done you will be in the terminal of the raspberry card which work like a linux terminal, you can now update an install the needed package (command: "apt update","apt upgrade").
we will need python so i have installed pyhton3 (apt install python3).
We will next have to learn openCV and install it in the raspberry.

I have update the tutorial on how to connect the raspberrypi:
[tutorial](https://github.com/YOUSSNDR/PolySnake/blob/2c97e4ca37ce17a8575b1211ac05783869601126/Raspberry%20pi/Raspberry%20pi%20zero%20config/config%20Raspberry%20pi%20zero%20W.md)