# ⏱️ Multithreaded C++ Timer
A multithreaded countdown timer built with C++. One thread handles the countdown, while another listens for user commands like `stop` or `reset`.
## 🔧 Features
- Real-time countdown in the terminal
- Accepts user input while timer runs (stop or reset)
- Uses C++11 threads and atomic flags for concurrency
## 🛠 How to Use
1. Save the code as `multithreaded_timer.cpp`
2. Compile with:
   ```bash
   g++ -std=c++11 -pthread multithreaded_timer.cpp -o timer
   ```
3. Run it:
   ```bash
   ./timer
   ```
4. While running, type:
   - `reset` — to restart the timer from the beginning
   - `stop` — to cancel the timer
## 🖥 Example Output
```
Enter countdown time (in seconds): 10
⏳ Time left: 10s
⏳ Time left: 9s
(reset typed)
🔄 Timer reset!
⏳ Time left: 10s
(stop typed)
🛑 Timer stopped by user.
```
## 🚀 Why Use This?
- Practice with C++ multithreading and atomics
- Useful for command-line countdown tasks
- Foundation for more advanced concurrent tools
## 👤 Author
Crafted with 🧠 by [@veyzohh](https://github.com/veyzohh)
