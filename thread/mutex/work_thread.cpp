#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable cv_;
std::string data_;
bool ready_ = false;
bool done_ = false;

void worker() {
  std::cout << "worker thread start " << std::endl;
  std::unique_lock<std::mutex> lock(mutex_);
  // wait at ready_ variable
  cv_.wait(lock, [] { return ready_; });

  // acquire the lock
  std::cout << "worker thread is processing data" << std::endl;
  data_ += "after processing";
  done_ = true;
  // manual unlocking before notifying,to avoid waking up
  lock.unlock();
  cv_.notify_one();
}

void master() {
  std::cout << "master thread start" << std::endl;
  data_ = "Example Data";
  {
    std::lock_guard<std::mutex> lock(mutex_);
    ready_ = true;
    std::cout << "master thread signals data ready for processing. "
              << std::endl;
  }
  // notify the worker thread to continue
  cv_.notify_one();

  // wait for the worker thread
  {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [] { return done_; });
  }
  std::cout << "back in master thread, data: " << data_ << std::endl;
}

int main(int argc, char* argv[]) {
  std::thread workerThread(worker);
  std::thread masterThread(master);

  workerThread.join();
  masterThread.join();

  return 0;
}