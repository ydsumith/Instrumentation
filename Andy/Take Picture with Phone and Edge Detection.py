# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 20:35:56 2020

@author: AndyD
"""

import cv2
import numpy as np
 
#image = "global"

def main():
    captureImage()
    rescaleImage()
    edgeDetection()

def captureImage():
    from time import sleep
key = cv2. waitKey(1)
cap = cv2.VideoCapture('rtsp://adalbol:@TouchedE1@10.15.4.74:8080/h264_ulaw.sdp')
#sleep(2)
while True:

    try:
        check, frame = cap.read()
        print(check) #prints true as long as the webcam is running
        print(frame) #prints matrix values of each framecd 
        cv2.imshow("Capturing", frame)
        key = cv2.waitKey(1)
        if key == ord('s'): 
            cv2.imwrite(filename='Object.jpg',img=frame)
            cap.release()

            
            break
        
        elif key == ord('q'):
            cap.release()
            cv2.destroyAllWindows()
            break
    
    except(KeyboardInterrupt):

        cap.release()

        cv2.destroyAllWindows()
        break
    
def rescaleImage():
    #load the image
    img = cv2.imread('Object.jpg',cv2.IMREAD_GRAYSCALE)
 
    #define the screen resulation
    screen_res = 1280, 720
    scale_width = screen_res[0] / img.shape[1]
    scale_height = screen_res[1] / img.shape[0]
    scale = min(scale_width, scale_height)
 
    #resized window width and height
    window_width = int(img.shape[1] * scale)
    window_height = int(img.shape[0] * scale)
 
    #cv2.WINDOW_NORMAL makes the output window resizealbe
    cv2.namedWindow('Resized Window', cv2.WINDOW_NORMAL)
 
    #resize the window according to the screen resolution
    cv2.resizeWindow('Resized Window', window_width, window_height)
    
    #resave image
    cv2.imwrite(filename='ObjectGrayScale.jpg',img=frame)
 
def edgeDetection():    
    #load the image
    img = cv2.imread('ObjectGrayScale.jpg')
    
    #edge detection
    edges = cv2.Canny(img,100,200)
    
    #save edge file
    cv2.imwrite(filename='ObjectEdgeDetection.jpg',img=frame)
    
    cv2.imshow('Resized Window', edges)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
 
if __name__ == "__main__":
    main()
