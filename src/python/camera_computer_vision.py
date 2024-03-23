import cv2
import numpy as np

# Start Camera
camera = cv2.VideoCapture(0)

while True:
    ret, frame = camera.read()

    # Convert Gray Scale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Apply Sobel Operator for edge detection
    sobel_x = cv2.Sobel(gray, cv2.CV_64F, 1, 0, ksize=5)
    sobel_y = cv2.Sobel(gray, cv2.CV_64F, 1, 0, ksize=5)
    edges = np.sqrt(sobel_x**2 + sobel_y**2)

    # Scale 0 to 255
    edges = np.uint8(edges / np.max(edges) * 255)

    # Join original image and edged image
    result = np.concatenate((frame,cv2.cvtColor(edges, cv2.COLOR_GRAY2bgr)), axis=1)

    # cv2.imshow('Visão Computacional', frame)
    cv2.imshow('Original vs Borda', result)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    
    camera.release()
    cv2.destroyAllWindows()