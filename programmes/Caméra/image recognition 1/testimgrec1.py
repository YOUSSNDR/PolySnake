# the imports:
import cv2
import math
import numpy as np

# image path:
path= "C:\Users\Ali08\OneDrive\Bureau\ecole d'ingé\PolySnake\programmes\Caméra\image recognition 1\imgtest1"
fileName="arrows.png"

# Read the image:
inputImage= cv2.imread(path + fileName)

# Grayscale conversion:
grayscaleImage = cv2.cvtColor(inputImage, cv2.COLOR_BGR2GRAY)
grayscaleImage = 255 - grayscaleImage

#find the big contours/blobs on the binary image:
contours, hierarchy = cv2.findContours(grayscaleImage, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)

# Process each contour 1-1:
for i,c in enumerate(contours):

    # Approximate the contour to a polygon:
    contoursPoly = cv2.approxPolyDP(c, 3, True)

    # Convert the polygon to a bounding rectangle:
    boundRect =cv2.boundingRect(contoursPoly)

    # Get the bounding rect's data:
    rectX = boundRect[0]
    rectY = boundRect[1]
    rectWidth = boundRect[2]
    rectHeight = boundRect[3]

    #Get the rect's area
    rectArea = rectWidth * rectHeight

    minBlobArea = 100

    # Check if blob is above the min area:
    if rectArea > minBlobArea:

        # Crop the roi:
        croppedImg = grayscaleImage[rectY:rectY + rectHeight, rectX:rectX + rectWidth]

        # Extend the borders for the skeleton:
        borderSize = 5
        croppedImg = cv2.copyMakeBorder(croppedImg, borderSize, borderSize, borderSize, borderSize, cv2.BORDER_CONSTANT)

        # Store a deep copy of the crop for results:
        grayscaleImageCopy = cv2.cvtColor(croppedImg, cv2.COLOR_GRAY2BGR)

        # Compute the skeleton:
        skeleton = cv2.ximgproc.thinning(croppedImg, None, 1)

        # Threshold the image so that white pixels get a value of 0
        # and black pixel a value of 10:

        _, binaryImage = cv2.threshold(skeleton, 128, 10, cv2.THRESH_BINARY)

        # Set the end-points kernel:
        h = np.array([[1, 1, 1],
                      [1, 10, 1],
                      [1, 1, 1]])
        #Convolve the image with kernel:
        imgFiltered=cv2.filter2D(binaryImage, -1, h)

        # Extract only the end-points pixels, those with
        # an intensity value of 110:
        binaryImage = np.where(imgFiltered == 110, 255, 0)
        # The above operation converted the image to 32-bit float,
        # convert back to 8-bit uint
        binaryImage = binaryImage.astype(np.uint8)

        # Find the X, Y location of all the end-points
        # pixels:
        Y, X = binaryImage.nonzero()

        # Check if I got points on my arrays:
        if len(X) > 0 or len(Y) > 0:
            # Reshape the arrays for K-means
            Y = Y.reshape(-1, 1)
            X = X.reshape(-1, 1)
            Z = np.hstack((X, Y))

            # K-means operates on 32-bit float data:
            floatPoints = np.float32(Z)

            # Set the convergence criteria and call K-means:
            criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
            _, label, center = cv2.kmeans(floatPoints, 2, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS)

            # Set the cluster count, find the points belonging
            # to cluster 0 and cluster 1:
            cluster1Count = np.count_nonzero(label)
            cluster0Count = np.shape(label)[0] - cluster1Count

            # Look for the cluster of max number of points
            # That cluster will be the tip of the arrow:
            maxCluster = 0
            if cluster1Count > cluster0Count:
                maxCluster = 1

                # Check out the centers of each cluster:
                matRows, matCols = center.shape
                # We need at least 2 points for this operation:
                if matCols >= 2:
                    # Store the ordered end-points here:
                    orderedPoints = [None] * 2
                    # Let's identify and draw the two end-points
                    # of the arrow:
                    for b in range(matRows):
                        # Get cluster center:
                        pointX = int(center[b][0])
                        pointY = int(center[b][1])
                        # Get the "tip"
                        if b == maxCluster:
                            color = (0, 0, 255)
                            orderedPoints[0] = (pointX, pointY)
                        # Get the "tail"
                        else:
                            color = (255, 0, 0)
                            orderedPoints[1] = (pointX, pointY)
                        # Draw it:
                        cv2.circle(grayscaleImageCopy, (pointX, pointY), 3, color, -1)
                        cv2.imshow("End Points", grayscaleImageCopy)
                        cv2.waitKey(0)

                        # Store the tip and tail points:
                        p0x = orderedPoints[1][0]
                        p0y = orderedPoints[1][1]
                        p1x = orderedPoints[0][0]
                        p1y = orderedPoints[0][1]
                        # Compute the sides of the triangle:
                        adjacentSide = p1x - p0x
                        oppositeSide = p0y - p1y
                        # Compute the angle alpha:
                        alpha = math.degrees(math.atan(oppositeSide / adjacentSide))

                        # Adjust angle to be in [0,360]:
                        if adjacentSide < 0 < oppositeSide:
                            alpha = 180 + alpha
                        else:
                            if adjacentSide < 0 and oppositeSide < 0:
                                alpha = 270 + alpha
                            else:
                                if adjacentSide > 0 > oppositeSide:
                                    alpha = 360 + alpha
