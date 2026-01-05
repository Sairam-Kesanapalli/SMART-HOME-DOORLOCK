import cv2
from deepface import DeepFace
import serial
import time

SERIAL_PORT = "COM10"    # replace with your FTDI COM (check Device Manager)
BAUD_RATE = 115200

ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # allow ESP to boot

AUTHORIZED_IMG = "authorized.jpg"
cap = cv2.VideoCapture(0)

last_action = 0
cooldown = 5  # seconds

while True:
    ret, frame = cap.read()
    if not ret:
        continue

    try:
        result = DeepFace.verify(frame, AUTHORIZED_IMG, enforce_detection=False)
        verified = result["verified"]
    except Exception as e:
        print("Detection error:", e)
        verified = False

    now = time.time()
    if now - last_action > cooldown:
        if verified:
            print("AUTHORIZED -> sending UNLOCK")
            ser.write(b"UNLOCK\n")
        else:
            print("UNAUTHORIZED -> sending ALARM")
            ser.write(b"ALARM\n")
        last_action = now

    cv2.imshow("Face Recognition", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
ser.close()
