import cv2

print("Before URL")
cap = cv2.VideoCapture('rtsp://admin:admin@192.168.1.4:8080/h264_ulaw.sdp')
print("After URL")

while True:

    print('About to start the Read command')
    ret, frame = cap.read()
    print('About to show frame of Video.')
    cv2.imshow("Capturing",frame)
    print('Running..')

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
