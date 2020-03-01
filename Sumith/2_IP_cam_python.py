# Written by Sumith Yesudasan
# Last modified FEB 29 2020

import cv2

print("Before URL")
cap = cv2.VideoCapture('rtsp://admin:admin@192.168.1.4:8080/h264_ulaw.sdp')
print("running")

increment = 1;

def rescale_frame(frame, percent):
    width = int(frame.shape[1] * percent/ 100)
    height = int(frame.shape[0] * percent/ 100)
    dim = (width, height)
    return cv2.resize(frame, dim, interpolation =cv2.INTER_AREA)

while increment < 1000:
    ret, framer = cap.read()
    
    frame = rescale_frame(framer, percent=50)
    
    cv2.imshow("Capturing",frame)
    
    increment = increment +1;

    #Need to work on the stopping criteria
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
