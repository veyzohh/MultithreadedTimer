#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <string>

std::atomic<bool> running(true);
std::atomic<bool> reset_requested(false);

void timer(int seconds) {
    while (running) {
        for (int i = seconds; i >= 0 && running; --i) {
            if (reset_requested) {
                std::cout << "\n🔄 Timer reset!\n";
                reset_requested = false;
                i = seconds;
            }

            std::cout << "\r⏳ Time left: " << i << "s " << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        if (running) {
            std::cout << "\n✅ Timer finished!\n";
            running = false;
        }
    }
}

void input_listener() {
    std::string command;
    while (running) {
        std::getline(std::cin, command);
        if (command == "stop") {
            std::cout << "\n🛑 Timer stopped by user.\n";
            running = false;
        } else if (command == "reset") {
            reset_requested = true;
        }
    }
}

int main() {
    int duration = 10; // default 10 seconds
    std::cout << "Enter countdown time (in seconds): ";
    std::cin >> duration;
    std::cin.ignore(); // clear newline from input buffer

    std::thread t1(timer, duration);
    std::thread t2(input_listener);

    t1.join();
    t2.join();

    return 0;
}
