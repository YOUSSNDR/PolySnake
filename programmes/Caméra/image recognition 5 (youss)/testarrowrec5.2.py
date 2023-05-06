import cv2
#import os
import numpy as np

#print(os.listdir("C:\Users\Ali08\OneDrive\Bureau\ecole d'ingé\PolySnake\programmes\Caméra\images"))

pic = cv2.imread("Arrow.png")
#cap = cv2.VideoCapture(0)
#result, pic = cap.read()
#we might use HSV color to inprove the code
hsv_pic = cv2.cvtColor(pic, cv2.COLOR_BGR2HSV)

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

def inrectangle(contour):
    max_contour = max(contours, key=cv2.contourArea)
    x1, y1, w1, h1 = cv2.boundingRect(max_contour)
    cv2.rectangle(pic, (x1, y1), (x1+w1, y1+h1),(200, 200,0), 2)
    #trouvons le centre du rectangle
    center_x= x1 + w1/2
    center_y= y1 + h1/2
    return(center_x, center_y)

#precise function to find the arrow tip
def find_tip(points, convex_hull):
    length = len(points)
    indices = np.setdiff1d(range(length), convex_hull)
    for i in range(2):
        j = indices[i] + 2
        if j > length - 1:
            j = length - j
        if np.all(points[j] == points[indices[i - 1] - 2]):
            return tuple(points[j])
#take the contour
contours, hierarchy = cv2.findContours(preprocess(pic), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
#check des couleurs
for i in range(len(contours)):
    mask = np.zeros(preprocess(pic).shape, np.uint8)
    cv2.drawContours(mask, [contours[i]], 0, 255, -1)
    # take the medium color
    b, g, r = cv2.mean(pic, mask=mask)[:3] # give the medium color in the pic, can be replace by the color of the midle point
    objet='objet' + str(i)
    print(objet, ':', [b, g, r])
    x, y, w, h = cv2.boundingRect(contours[i])
    #if g<80 and b<80 and r>180:
    #if the inside is red show the contour in green
    if r>200 and g<80 and b< 80:
        cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        """#test# on prend le périmètre du contour sert a la
        #précision dans la commande arclength qui nous permet de relever les angles de la flèches
        peri = cv2.arcLength(contours[i], True)
        approx=cv2.approxPolyDP(contours[i],0.025*peri,True)
        hull = cv2.convexHull(approx, returnPoints=False)#permet d'avoir une liste des coordonnées des angles
        sides=len(hull)# permet d'avoir le nombre de côté

        #test# """
        peri = cv2.arcLength(contours[i], True)
        epsilon= 0.025*peri
        approx=cv2.approxPolyDP(contours[i],epsilon,True)
        hull = cv2.convexHull(approx, returnPoints=False)
        #cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        #cv2.drawContours(pic, contours[i], -1, (0, 255, 0), 3)

        # an arrow will have 7 vertices (2 for the head,5 for the arrow shaft)
        if len(approx)==7:
            #center of the rectangle containing the arrow
            center_x, center_y=inrectangle(contours[i])
            #position of the arrowhead
            """arrowhead= approx[0][0]
            arrowhead_x= arrowhead[0]
            arrowhead_y= arrowhead[1]"""
            arrow_tip = find_tip(approx[:,0, :], hull.squeeze())
            arrowhead_x= arrow_tip[0]
            arrowhead_y= arrow_tip[1]

            #we form two list gathering coordinates on x and on y
            coo_x=np.array([arrowhead_x, center_x])
            coo_y=np.array([arrowhead_y, center_y])
            if abs(coo_x[0]-coo_x[1])>abs(coo_y[0]-coo_y[1]):
                if coo_x[0]-coo_x[1]>0:
                    direction="droite"
                else:
                    direction="gauche"
            else:
                if -(coo_y[0]-coo_y[1])>0:# y axis is up side down
                    direction="haut"
                else:
                    direction="bas"
        objet=objet + ' vers ' + direction
        cv2.circle(pic, (int(center_x), int(center_y)), 3, (0, 255, 0), -1)
        cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        cv2.drawContours(pic, contours[i], -1, (0, 255, 0), 3)
        cv2.circle(pic, (int(coo_x[0]), int(coo_y[0])), 3, (255, 0, 0), -1)
        print(coo_x)
        print(coo_y)
    """ # else show the contour in blue
    else:
        cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)
        cv2.drawContours(pic, contours[i], -1, (255, 0, 0), 3)
"""
cv2.imshow("pic", pic)
cv2.waitKey(0)