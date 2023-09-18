#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

int num_;
std::mutex num_mutex_;

void Inrecment(int n) {
  for (int i = 0; i < 5; i++) {
    num_mutex_.lock();
    ++num_;
    std::cout << "id: " << std::this_thread::get_id() << " num: " << num_
              << std::endl;
    num_mutex_.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
}

int main(int argc, char* argv[]) {
  std::thread t1{Inrecment, 0};
  std::thread t2{Inrecment, 1};

  t1.join();
  t2.join();

  return 0;
}