import numpy as np
# 1 = left , 2 = right
import cv2
# focal length of camera 1
fx1 ,fy1 = 703.29 , 704.19
#focal length of camera2
fx2 ,fy2  = 720.60 , 722.24
#center of camera1
p1 , q1 = 339.90 , 257.50
#center of second camera
p2 , q2 = 334.95 , 263.99
#distance between cameras
d = 7.1
#real world coordinates
x,y,z = 0,0,0
#pixal co-ordinates
p,q = 0,0
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
cap1 = cv2.VideoCapture(1)
cap2 = cv2.VideoCapture(2)
while(True):
    # Capture frame-by-frame
    ret1, frame1 = cap1.read()
    ret2, frame2 = cap2.read()

    gray = cv2.cvtColor(frame1, cv2.COLOR_BGR2GRAY)
    faces1 = face_cascade.detectMultiScale(frame1, 1.3, 5)
    faces2 = face_cascade.detectMultiScale(frame2, 1.3, 5)
    for (x,y,w,h) in faces1:
     p ,q  = x+(w/2) , y + (w/2)
    for (x,y,w,h) in faces2:
       t = x+(w/2)
       z = d/abs((t/fx2) - (p/fx1))
       print z
       x = ((abs(p-p1))*z)/fx1
       y = ((abs(q-q1))*z)/fy1
       print(x)
       print(y)
    cv2.imshow('img1',frame1)
    cv2.imshow('img2',frame2)
    cv2.waitKey(1)
cv2.destroyAllWindows()