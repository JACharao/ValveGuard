# Valve-Guard 🛡️

**Valve-Guard** is a low-level system resource monitor developed in **C** for **Linux/WSL2** environments.

The project was born from the goal of understanding how the Linux Kernel exposes hardware metrics through the `/proc` virtual file system. It is a practical study of systems engineering focused on infrastructure and performance.

---

## 🚀 Current Features

- [x] Static RAM Total reading via `/proc/meminfo`.
- [ ] Free and Used Memory calculation (Work in progress).
- [ ] CPU load monitoring (Planned).
- [ ] Colorized Terminal Interface (Planned).

---

## 🛠️ Technologies Used

* **Language:** C (C11 Standard)
* **System:** Linux / Ubuntu (WSL2)
* **Compiler:** GCC
* **Concepts:** File handling, String parsing, Memory management.

---

## 💻 How to Build and Run

Make sure you have `build-essential` installed on your Linux system.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YOUR_USERNAME/valve-guard.git](https://github.com/YOUR_USERNAME/valve-guard.git)
   cd valve-guard

2. **Compile the code:**
   ```bash
   gcc valveGuard.c -o valveGuard

3. **Run the executable:**
   ```bash
   ./valveGuard
