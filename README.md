# Valve-Guard 🛡️

**Valve-Guard** is a low-level system resource monitor developed in **C** for **Linux/WSL2** environments.

The project was born from the goal of understanding how the Linux Kernel exposes hardware metrics through the `/proc` virtual file system. It is a practical study of systems engineering focused on infrastructure and performance.

---

## 🚀 Features (v0.4)

- [x] **CPU Identification:** Detects the processor model using `/proc/cpuinfo`.
      
- [x] **Real-time RAM Monitoring:** Reads Total, Free, and Available RAM from `/proc/meminfo`.
      
- [x] **System Uptime:** Tracks system session duration via `/proc/uptime`.

- [x] **Dynamic Progress Bar:** Visual representation of RAM usage.

- [x] **Colorized Interface:** ANSI colors for better data visualization.
      
- [ ] **CPU Load Monitoring:** (Planned).

---

## 🎨 Visuals & Interface
The dashboard uses ANSI Escape Codes to provide a dynamic and color-coded experience based on system load:

Progress Bar: A 20-segment bar [##########----------] that updates every second.

Smart Colors:

🟢 Green: Usage below 50% (Healthy).

🟡 Yellow: Usage between 50% and 80% (Moderate).

🔴 Red: Usage above 80% (Critical).

---

## 🛠️ Technologies Used

* **Language:** C (C11 Standard)
* **System:** Linux / Ubuntu (WSL2)
* **Compiler:** GCC
* **Concepts:** The program uses a `while(1)` loop combined with `usleep/sleep` to poll kernel files. Key concepts applied:

* **File Pointers:** Efficiently navigating through `/proc` text streams.
  
* **String Parsing:** Using `sscanf` with format specifiers to isolate numeric data.
  
* **ANSI Escape Codes:** `\033[H\033[J` used to refresh the terminal without flickering.
  
---

## ⚠️ Important Note on WSL2 
During development, you might notice that RAM values stay relatively static. This is **expected behavior** in WSL2 because:
1. **Memory Ballooning:** WSL2 reserves a fixed chunk of Windows RAM.
   
2. **Kernel Isolation:** Changes in Windows RAM (like opening Chrome) are not immediately visible inside the Linux VM unless a process is running **inside the Ubuntu environment**.
   
3. **Uptime Test:** The "Uptime" counter in this dashboard proves the real-time polling is working correctly.

---

## 💻 How to Build and Run

Make sure you have `build-essential` installed on your Linux system.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/JACharao/valve-guard.git](https://github.com/JACharao/valve-guard.git)
   cd valve-guard

2. **Compile the code:**
   ```bash
   gcc valveGuard.c -o valveGuard

3. **Run the executable:**
   ```bash
   ./valveGuard
