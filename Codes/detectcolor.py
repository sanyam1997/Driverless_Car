# import the necessary packages
import numpy as np
import cv2
 

image = cv2.imread("color.jpg")

#Convert BGR to HSV
hsv=cv2.cvtColor(image,cv2.COLOR_BGR2HSV)

weaker=np.array([50,100,100])
stronger=np.array([80,255,255])
mask=cv2.inRange(hsv,weaker,stronger)
res = cv2.bitwise_and(hsv,hsv, mask= mask)

cv2.imshow('Image',image)
cv2.imshow('Result',mask)
cv2.imshow('res',res)
cv2.imwrite('colordetect1.png',res)
cv2.waitKey(0)
cv2.destroyAllWindows()
