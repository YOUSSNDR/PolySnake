import cv2
import numpy as np

# Initialize camera object
cap = cv2.VideoCapture(0)  # Use 0 as the camera index for the default webcam, you can change it to other indices if you have multiple cameras

# Capture a single frame from the camera
ret, frame = cap.read()

# Convert frame to grayscale
gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

# Apply Gaussian blur to the frame to reduce noise
gray_blur = cv2.GaussianBlur(gray, (5, 5), 0)

# Detect edges in the frame using Canny edge detection
edges = cv2.Canny(gray_blur, 50, 150)

# Find contours in the edge map
contours, hierarchy = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Initialize counter for number of arrows found
arrow_count = 0

# Loop through each contour and check if it's an arrow
for contour in contours:
    # Approximate the contour to a polygon
    epsilon = 0.02 * cv2.arcLength(contour, True)
    approx = cv2.approxPolyDP(contour, epsilon, True)

    # If the polygon has 7 vertices, it's likely an arrow (2 vertices for arrowhead, 5 for arrow shaft)
    if len(approx) == 7:
        # Extract the coordinates of arrowhead vertices
        arrowhead = approx[0][0]
        arrowhead_x = arrowhead[0]
        arrowhead_y = arrowhead[1]

        # Get the center of the frame
        center_x = frame.shape[1] // 2

        # Determine the direction of the arrow based on arrowhead position
        direction = "Right" if arrowhead_x > center_x else "Left"

        # Draw the contour of the arrow in green color
        cv2.drawContours(frame, [contour], 0, (0, 255, 0), 2)

        # Put text label "Arrow" and direction at the top left corner of the arrow
        x, y, w, h = cv2.boundingRect(contour)
        cv2.putText(frame, "Arrow", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        cv2.putText(frame, direction, (x, y - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

        # Increment the arrow counter
        arrow_count += 1

# Print the number of arrows found
cv2.putText(frame, "Number of arrows found: {}".format(arrow_count), (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

# Display the frame with arrows highlighted
cv2.imshow("Arrow Detection", frame)

# Wait for a key press and then close all windows
cv2.waitKey(0)
cv2.destroyAllWindows()

# Release camera
cap.release()
