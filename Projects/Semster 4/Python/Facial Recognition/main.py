import face_recognition
import cv2
import numpy as np
import csv
from datetime import datetime

# Get a reference to webcam
video_capture = cv2.VideoCapture(0)

# Load Known Faces
kaushik_image = face_recognition.load_image_file(r"Facial Recognition\faces\Kaushik.jpg")
kaushik_face_encoding = face_recognition.face_encodings(kaushik_image)[0]

sahil_image = face_recognition.load_image_file(r"Facial Recognition\faces\Sahil.jpg")
sahil_face_encoding = face_recognition.face_encodings(sahil_image)[0]

abhishek_image = face_recognition.load_image_file(r"Facial Recognition\faces\Abhishek.jpg")
abhishek_face_encoding = face_recognition.face_encodings(abhishek_image)[0]

known_face_encodings = [
    kaushik_face_encoding,
    sahil_face_encoding,
    abhishek_face_encoding
]
known_face_names = [
    "Kaushik",
    "Sahil",
    "Abhishek"
]

# List of Expected Attendees
students = known_face_names.copy()
face_locations = []
face_encodings = []

# Get the Current Date & Time
now = datetime.now()
current_time = now.strftime("%H:%M:%S")
current_date = now.strftime("%d-%m-%Y")

# Open the CSV File
f = open(rf"Facial Recognition\attendance\{current_date}.csv", "w+", newline="")
writer = csv.writer(f)
while True:
    _, frame = video_capture.read()
    small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
    rgb_small_frame = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)

    # Recognize Faces
    face_locations = face_recognition.face_locations(rgb_small_frame)
    face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

    for face_encoding in face_encodings:
        matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
        face_distances = face_recognition.face_distance(known_face_encodings, face_encoding)
        best_match_index = np.argmin(face_distances)

        if matches[best_match_index]:
            name = known_face_names[best_match_index]

        # Add text if a person is present
        if name in known_face_names:
            font = cv2.FONT_HERSHEY_DUPLEX
            fontScale = 1
            if name == "Kaushik":
                fontColor = (255, 0, 0)  # Red for Kaushik
            elif name == "Sahil":
                fontColor = (0, 255, 0)  # Green for Sahil
            elif name == "Abhishek":
                fontColor = (0, 0, 255)  # Blue for Abhishek
            thickness = 3
            lineType = 2
            bottomLeftCornerOfText = (10, 50 + 30 * known_face_names.index(name))
            cv2.putText(frame, name + " is Present", bottomLeftCornerOfText, font, fontScale, fontColor, thickness, lineType)

            if name in students:
                students.remove(name)
                current_time = now.strftime("%H:%M:%S")
                writer.writerow([name, current_time])
            
    cv2.imshow("Attendance", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

video_capture.release()
cv2.destroyAllWindows()
f.close()