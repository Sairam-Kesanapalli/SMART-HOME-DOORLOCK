# AI-Based Smart Home Door Lock System

This project implements an AI-based smart security and door locking system using face recognition and embedded control.  
The system identifies authorized and unauthorized individuals using computer vision and controls a buzzer and door lock mechanism through an ESP32 module.

Due to hardware limitations encountered during development, the final implementation uses a **local machine learning server** and a **laptop webcam** instead of full ESP32-CAM cloud-based operation.

---

## Project Overview

The goal of this project is to design an intelligent security system capable of:
- Detecting a person at the door
- Performing face recognition
- Granting or denying access based on authorization
- Triggering alerts for unauthorized access

The project focuses on learning and integrating **Embedded Systems, Computer Vision, and AI-based decision making**.

---

## Features

- Face detection and recognition using OpenCV
- Authorized image-based authentication
- Serial communication between Python and ESP32
- Buzzer activation for unauthorized access
- Door lock control logic (tested partially)
- Local ML processing without cloud dependency

---

## System Architecture

**Workflow:**
1. Laptop webcam captures an image of the person.
2. Python-based ML model performs face recognition.
3. Face is compared with stored authorized images.
4. Decision is sent to ESP32 via serial communication.
5. ESP32 controls buzzer and lock accordingly.

---

## Tech Stack

- Python
- OpenCV
- NumPy
- Serial Communication (PySerial)
- ESP32 (Arduino IDE)
- Embedded Systems

---

## Project Status and Limitations

 **Partial Implementation**

- ESP32-CAM module was non-functional due to hardware failure.
- ESP32 Wi-Fi was not working, so cloud integration was not possible.
- Laptop webcam was used instead of ESP32-CAM.
- Face recognition runs on a local server.
- Relay/solenoid lock hardware could not be fully tested.
- Email alerts and mobile app integration were not implemented.

Despite these limitations, the project successfully demonstrates:
- AI-based face recognition
- Embedded system control logic
- End-to-end decision-making flow

---

## Future Improvements

- Working ESP32-CAM integration
- Cloud-based face recognition
- Mobile app for remote access
- Email alerts for unauthorized access
- Live video streaming
- Additional sensors (PIR, gas, fire)

---

## Authors

- Kesanapalli Madhava Naga Venkata Sai Ram  
- J. Durgesh  
- P. Avinash  

Department of Electronics and Communication Engineering  
IIIT Dharwad


