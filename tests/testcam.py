import cv2
import time

# Gunakan cv2.CAP_V4L2 untuk memaksa OpenCV menggunakan driver Video4Linux2
# Catatan: Jika 0 membuka kamera laptop (atau error), ubah cam_index menjadi 2 atau 4
cam_index = 2
cap = cv2.VideoCapture(cam_index, cv2.CAP_V4L2)

# 1. Paksa format kompresi MJPG (Solusi utama FPS rendah di Linux)
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))

# 2. Atur resolusi target
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 360)

# 3. Atur target FPS
cap.set(cv2.CAP_PROP_FPS, 30)

if not cap.isOpened():
    print(f"Kamera dengan index {cam_index} tidak dapat diakses.")
    print("Saran: Ubah variabel 'cam_index' menjadi 2 atau 4 untuk membaca port USB eksternal.")
    exit()

# Variabel untuk menghitung FPS aktual
prev_frame_time = 0

print("Kamera berhasil dibuka. Tekan 'q' pada jendela video untuk keluar.")

while True:
    # Membaca frame dari kamera
    ret, frame = cap.read()
    
    if not ret:
        print("Gagal menerima sinyal gambar dari USB. Keluar...")
        break

    # Menghitung FPS aktual di layar
    new_frame_time = time.time()
    if new_frame_time - prev_frame_time > 0:
        fps = int(1 / (new_frame_time - prev_frame_time))
    else:
        fps = 0
    prev_frame_time = new_frame_time

    # Menambahkan teks FPS berwarna hijau di pojok kiri atas
    cv2.putText(frame, f"FPS Aktual: {fps}", (10, 35), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Menampilkan frame di jendela
    cv2.imshow('Uji Webcam', frame)

    # Tekan tombol 'q' untuk menutup jendela
    if cv2.waitKey(1) == ord('q'):
        break

# Membersihkan memori dan port USB setelah selesai
cap.release()
cv2.destroyAllWindows()