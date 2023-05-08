import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(23, GPIO.OUT) # Trig
GPIO.setup(24, GPIO.IN) # Echo

def measure_distance():
    # Send a 10us pulse to trigger the sensor
    GPIO.output(23, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(23, GPIO.LOW)

    # Wait for the echo response
    while GPIO.input(24) == 0:
        pulse_start = time.time()

    while GPIO.input(24) == 1:
        pulse_end = time.time()

    # Calculate the distance
    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150 # speed of sound is 34300 cm/s, but it travels to and back
    distance = round(distance, 2) # round to two decimal places

    return distance

distance = measure_distance()
print("Distance: {} cm".format(distance))
