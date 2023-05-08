import cv2
#import os
import numpy as np
import serial
#import RPi.GPIO as GPIO
import time

limit=8 # 8 cm distance where the snake stops to make a decision
#arduinoNANO = serial.Serial(port='COM15', baudrate=115200, timeout=.1) #pas de Nano tout par raspberry
#arduinoUNO = serial.Serial(port='COM14', baudrate=9600, timeout=.1)
"""GPIO.setmode(GPIO.BOARD)
GPIO.setup(23, GPIO.OUT) # Trig
GPIO.setup(24, GPIO.IN) # Echo
"""
"""def read(): #allow us to read the values given by the arduinoNano
    data = arduinoNano.readline() 
    return data
"""
def write(x):
    arduinoUNO.write(bytes(x,'utf-8')) # send an int value to the arduino uno

#on initialise l'arduino UNO
#write(0)
"""
def distance():#check the distance to the wall
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
    distance = pulse_duration * 17000 # speed of sound is approximately 34000 cm/s, but it travels to and back
    distance = round(distance, 2) # round to two decimal places

    return distance
"""
#preprocess to detect easier all the contours
def preprocess(img): #make the coutours easier to see
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) # take the gray version of the image
    img_blur = cv2.GaussianBlur(img_gray, (5, 5), 1) #apply a GaussianBlur on the image
    img_canny = cv2.Canny(img_blur, 50, 50)
    kernel = np.ones((3, 3))
    img_dilate = cv2.dilate(img_canny, kernel, iterations=2)
    erode = cv2.erode(img_dilate, kernel, iterations=1)
    return erode

#inrectangle put the contour in a rectangle and give the center
def inrectangle(contour,pic): # draw a rectangle around the arrow
    max_contour = max(contour, key=cv2.contourArea)
    x1, y1, w1, h1 = cv2.boundingRect(max_contour)
    cv2.rectangle(pic, (x1, y1), (x1+w1, y1+h1),(200, 200,0), 2)
    #trouvons le centre du rectangle
    center_x = x1 + w1/2
    center_y = y1 + h1/2
    return(center_x, center_y)

#precise function to find the arrow tip
def find_tip(points, convex_hull): #return the position of the arrow tip
    length = len(points)
    indices = np.setdiff1d(range(length), convex_hull)
    for i in range(2):
        j = indices[i] + 2
        if j > length - 1:
            j = length - j
        if np.all(points[j] == points[indices[i - 1] - 2]):
            return tuple(points[j])


#True program
def arrow_check():
    pic = cv2.imread("Arrow.png")
    #cap = cv2.VideoCapture(0) #take a picture
    #result, pic = cap.read() #read the picture

    # we use HSV color to improve the code
    hsv_pic = cv2.cvtColor(pic, cv2.COLOR_BGR2HSV)

    # we take all the contours
    contours, hierarchy = cv2.findContours(preprocess(pic), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    for i in range(len(contours)):
        objet = 'objet' + str(i)
        #first let's check if this is an arrow
        peri = cv2.arcLength(contours[i], True) # take the perimeter of the contours
        epsilon = 0.025 * peri #give the precision for the approxPolyDP function
        approx = cv2.approxPolyDP(contours[i], epsilon, True) #approximate the contour
        hull = cv2.convexHull(approx, returnPoints=False) # to find the convex outline

        # an arrow will have 7 vertices (2 for the head, 5 for the arrow shaft)
        if len(approx) == 7:
            # take the color in the center of the rectangle containing the contour
            cx, cy = inrectangle(contours[i],pic) #take the coordinate of the center of the rectangle
            cx, cy = int(cx), int(cy) #turn them to integer
            pixel_center = hsv_pic[cy, cx]
            hue_value = pixel_center[0] # take the color of the center pixel of the rectangle

            #print(objet, ': ', hue_value)  # debug
            x, y, w, h = cv2.boundingRect(contours[i])#coordonate of the rectangle containing the contour

            # now let's check the color
            if hue_value < 5 or hue_value > 170: #red color range
                cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2) #write on the image

                #we can now check the direction
                #we take the coordinate of the arrowhead
                arrow_tip = find_tip(approx[:, 0, :], hull.squeeze())
                arrowhead_x = arrow_tip[0]
                arrowhead_y = arrow_tip[1]

                # we form two list gathering coordinates on x and on y
                coo_x = np.array([arrowhead_x, cx])
                coo_y = np.array([arrowhead_y, cy])

                direction = 'inconnue' #we don't know now the direction
                decision = 0

                #let's compare the distances on the x axis and the y axis to found the direction
                if abs(coo_x[0] - coo_x[1]) > abs(coo_y[0] - coo_y[1]):
                    #now we watch if the distance is positif
                    if coo_x[0] - coo_x[1] > 0:
                        direction = "droite"
                        decision = 1
                    else:
                        direction = "gauche"
                        decision = 2
                else:
                    if -(coo_y[0] - coo_y[1]) > 0:  # y axis is up side down
                        direction = "haut"
                        decision = 0
                    else:
                        direction = "bas"
                        decision = 3

                #we write the information on the picture
                objet = objet + ' vers ' + direction
                cv2.circle(pic, (int(cx), int(cy)), 3, (0, 255, 0), -1)
                cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv2.drawContours(pic, contours[i], -1, (0, 255, 0), 3)
                cv2.circle(pic, (int(coo_x[0]), int(coo_y[0])), 3, (255, 0, 0), -1)
                #print(coo_x)#debug
                #print(coo_y)#debug
                cv2.imshow("pic", pic) #show the picture
                cv2.waitKey(0) #keep it till we close it
                return decision #return the int decision that we will send to the arduino Uno

#arrow_check()

#cv2.imshow("pic", pic)
#cv2.waitKey(0)# value 1 to let it close the picture by itself

"""while True:
    # let s first get the distance value
    #distance = read() #with the arduino Nano
    distance=distance() # with the raspberry
    if distance < limit:
        write(4) # stop the snake
        decision=arrow_check()  # start the image recognition
        start_time=time.perf_counter()
        end_time=0
        while end_time<2:# turn for 2 seconds
            if decision==0: #STOP (up arrow)
                write(4)
            elif decision==1: #RIGHT
                write(1)
            elif decision==2: #LEFT
                write(2)
            elif decision==3: #BACK (down arrow)
                write(3)
            else : #did not recognise
                write(4) #stop
                time.sleep(2) #wait 2 second to check again

            end_time= time.perf_counter()-start_time
        
        write(0) # stop turning and go forward
"""
print(arrow_check())