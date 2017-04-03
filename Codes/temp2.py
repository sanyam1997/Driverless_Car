import numpy as np
import cv2

cap1 = cv2.VideoCapture(1)
cap2 = cv2.VideoCapture(2)


while(True):
    # Capture frame-by-frame
    ret1, frame1 = cap1.read()
    ret2, frame2 = cap2.read()

    # Our operations on the frame come here

    cv2.imshow('frame1',frame1)
    cv2.imshow('frame2', frame2)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap1.release()
cap2.release()
cv2.destroyAllWindows()
