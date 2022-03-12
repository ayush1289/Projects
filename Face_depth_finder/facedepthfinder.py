
import cv2
import mediapipe as mp
import cvzone
from cvzone.FaceMeshModule import FaceMeshDetector

cap = cv2.VideoCapture(0)
detector = FaceMeshDetector(maxFaces=1)
while True:
    success, img = cap.read()
    img, faces = detector.findFaceMesh(img, draw=False)

    if faces:
        face = faces[0]
        leftPoint = face[374]
        rightPoint = face[145]
        
        w, _ = detector.findDistance(leftPoint, rightPoint)

        cv2.circle(img,(320,240),5,(255,0,255),cv2.FILLED)
        cv2.circle(img,face[1],5,(255,0,255),cv2.FILLED)
        cv2.line(img,(320,240),face[1],(0,255,0),3)


    # Finding focal length

    # d=50
    # f=(w*d)/W
    # print(f)
    W = 6.3
    f = 480
    d = (W*f)/w
    cvzone.putTextRect(img, f'depth:{int(d)}cm',
                       (face[10][0]-100, face[10][1]-50), scale=2)
                       
    
   

    cv2.imshow("image", img)
    cv2.waitKey(1)
