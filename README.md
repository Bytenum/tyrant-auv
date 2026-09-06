# tyrant-auv
Autonomous Underwater Vehicle development platform
tyrant-auv/
├── README.md               # Dokumentasi utama repositori
├── .gitignore              # Daftar file yang diabaikan oleh Git
├── docs/                   # Dokumentasi teknis proyek
│   ├── architecture/       # Desain sistem dan arsitektur wahana
│   └── protocol/           # Dokumentasi protokol komunikasi
├── protocol/               # Implementasi protokol komunikasi (schema & parser)
│   ├── schema/             # Definisi pesan/struktur data
│   └── include/            # Header files untuk library protokol
├── firmware/               # Kode sumber mikrokontroler (Low-level)
│   ├── teensy/             # Firmware Teensy (pembacaan sensor & kendali aktuator)
│   └── esp32/              # Firmware ESP32 (telemetri & IoT)
├── companion/              # Kode untuk Companion Computer (High-level)
│   └── raspberry-pi/       # Skrip pemrosesan data utama (ROS/komunikasi tingkat tinggi)
├── simulation/             # Lingkungan simulasi wahana
│   ├── dynamics/           # Model dinamika AUV (surge, sway, heave, dll.)
│   ├── sensors/            # Pemodelan sensor virtual
│   ├── estimation/         # Algoritma estimasi state (misal: EKF)
│   ├── control/            # Algoritma kendali (misal: PID, LMPC)
│   └── allocation/         # Thrust allocation matrix / distribusi gaya thruster
├── gcs/                    # Ground Control Station (UI dan pemantauan darat)
├── tools/                  # Script utilitas (build, kalibrasi, logging)
└── tests/                  # Unit test dan integration test
