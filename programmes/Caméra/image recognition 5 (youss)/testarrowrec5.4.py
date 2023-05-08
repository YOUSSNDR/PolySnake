import cv2
#import os
import numpy as np

#preprocess to detect easier all the contours
def preprocess(img):
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    img_blur = cv2.GaussianBlur(img_gray, (5, 5), 1)
    img_canny = cv2.Canny(img_blur, 50, 50)
    kernel = np.ones((3, 3))
    img_dilate = cv2.dilate(img_canny, kernel, iterations=2)
    erode = cv2.erode(img_dilate, kernel, iterations=1)
    return erode

#inrectangle put the contour in a rectangle and give the center
def inrectangle(contour):
    max_contour = max(contours, key=cv2.contourArea)
    x1, y1, w1, h1 = cv2.boundingRect(max_contour)
    cv2.rectangle(pic, (x1, y1), (x1+w1, y1+h1),(200, 200,0), 2)
    #trouvons le centre du rectangle
    center_x = x1 + w1/2
    center_y = y1 + h1/2
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


#True program
pic = cv2.imread("Arrow.png")
#cap = cv2.VideoCapture(0)
#result, pic = cap.read()
#we use HSV color to inprove the code
hsv_pic = cv2.cvtColor(pic, cv2.COLOR_BGR2HSV)

# we take all the contour
contours, hierarchy = cv2.findContours(preprocess(pic), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

def arrow_check(contours):
    for i in range(len(contours)):
        objet = 'objet' + str(i)
        #first let's check if this is an arrow
        peri = cv2.arcLength(contours[i], True)
        epsilon = 0.025 * peri
        approx = cv2.approxPolyDP(contours[i], epsilon, True)
        hull = cv2.convexHull(approx, returnPoints=False)

        # an arrow will have 7 vertices (2 for the head, 5 for the arrow shaft)
        if len(approx) == 7:
            # take the color in the center of the rectangle containing the contour
            cx, cy = inrectangle(contours[i])
            cx, cy = int(cx), int(cy)
            pixel_center = hsv_pic[cy, cx]
            hue_value = pixel_center[0]

            print(objet, ': ', hue_value)  # debug
            x, y, w, h = cv2.boundingRect(contours[i])#coordonate of the rectangle containig the contour
            # now let's check the color
            if hue_value < 5 or hue_value > 170:
                cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

                #we can now check the direction
                #we take the coordonate of the arrowhead
                arrow_tip = find_tip(approx[:, 0, :], hull.squeeze())
                arrowhead_x = arrow_tip[0]
                arrowhead_y = arrow_tip[1]

                # we form two list gathering coordinates on x and on y
                coo_x = np.array([arrowhead_x, cx])
                coo_y = np.array([arrowhead_y, cy])

                direction = 'inconnue'
                #let's compare the distances to found the direction
                if abs(coo_x[0] - coo_x[1]) > abs(coo_y[0] - coo_y[1]):
                    if coo_x[0] - coo_x[1] > 0:
                        direction = "droite"
                    else:
                        direction = "gauche"
                else:
                    if -(coo_y[0] - coo_y[1]) > 0:  # y axis is up side down
                        direction = "haut"
                    else:
                        direction = "bas"
                objet = objet + ' vers ' + direction
                cv2.circle(pic, (int(cx), int(cy)), 3, (0, 255, 0), -1)
                cv2.putText(pic, objet, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv2.drawContours(pic, contours[i], -1, (0, 255, 0), 3)
                cv2.circle(pic, (int(coo_x[0]), int(coo_y[0])), 3, (255, 0, 0), -1)
                print(coo_x)#debug
                print(coo_y)#debug

arrow_check(contours)

cv2.imshow("pic", pic)
cv2.waitKey(0)