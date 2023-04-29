import cv2
#import os
import numpy as np

#print(os.listdir("C:\Users\Ali08\OneDrive\Bureau\ecole d'ingé\PolySnake\programmes\Caméra\images"))

#pic = cv2.imread("Arrow.png")
cap = cv2.VideoCapture(0)
result, pic = cap.read()

#adapting the image for the fincontours command
"""def  preprocess(pic):
    #image on grayscale
    gray = cv2.cvtColor(pic, cv2.COLOR_BGR2GRAY)
    #threshold the image
    ret,thresh  = cv2.threshold(gray, 100, 255, 0)
    return thresh """

def preprocess(img):
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    img_blur = cv2.GaussianBlur(img_gray, (5, 5), 1)
    img_canny = cv2.Canny(img_blur, 50, 50)
    kernel = np.ones((3, 3))
    img_dilate = cv2.dilate(img_canny, kernel, iterations=2)
    erode = cv2.erode(img_dilate, kernel, iterations=1)
    return erode

#take the contour
contours, hierarchy = cv2.findContours(preprocess(pic), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
#check des couleurs
for i in range(len(contours)):
    mask = np.zeros(preprocess(pic).shape, np.uint8)
    cv2.drawContours(mask, [contours[i]], 0, 255, -1)
    # take the medium color
    color = cv2.mean(pic, mask=mask)[:3]
    objet='objet' + str(i)
    print(objet, ':', color)
    x, y, w, h = cv2.boundingRect(contours[i])
    #if color[0]<80 and color[1]<80 and color[2]>180:
    if color[2] >= int(color[0] + color[1] - 30):
        cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        cv2.drawContours(pic, contours[i], -1, (0, 255, 0), 3)
    else:
        cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)
        cv2.drawContours(pic, contours[i], -1, (255, 0, 0), 3)

cv2.imshow("pic", pic)
cv2.waitKey(0)