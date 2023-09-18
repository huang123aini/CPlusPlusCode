#include <condition_variable>
#include <deque>
#include <iostream>
#include <mutex>
#include <thread>

template <typename T>
class BlockQueue {
 public:
  void push(T const& value) {
    {
      std::unique_lock<std::mutex> lock(d_mutex_);
      d_queue_.push_front(value);
    }
    d_condition_.notify_one();
  }

  T pop() {
    std::unique_lock<std::mutex> lock(d_mutex_);
    d_condition_.wait(lock, [=] { return !d_queue_.empty(); });
    T result(std::move(d_queue_.back()));
    d_queue_.pop_back();
    return result;
  }

 private:
  std::mutex d_mutex_;
  std::condition_variable d_condition_;
  std::deque<T> d_queue_;
};

int main(int argc, char* argv[]) {
  BlockQueue<int> block_queue_;

  std::thread t1([&]() {
    for (int i = 0; i < 20; i++) {
      block_queue_.push(i);
      std::cout << "push: " << i << std::endl;
    }
  });

  std::thread t2([&]() {
    int ret = block_queue_.pop();
    for (int i = 0; i < 20; i++) {
      std::cout << "pop: " << ret << std::endl;
    }
  });

  t1.join();
  t2.join();

  return 0;
}
