#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>


/**
  1、condition_variable类型的变量：等待线程和唤醒线程之间的同步操作都依赖该变量。
  2、一个共享条件(condition):
  3、一个互斥锁mutex: 这个额外的mutex是为了保证能够正常唤醒
  4、wait线程:当condition不满足的时候需要等待，直到条件满足了才做自己的事情。
  5、notify线程：做完自己的事情后修改condition变量并唤醒等待线程。
 */

int main(int argc, char* argv[]) {
  std::queue<int> goods;
  std::mutex mtx_;
  std::condition_variable cv_;
  bool done_ = false;
  static int count = 0;

  // 生产者
  std::thread producer([&]() {
    for (int i = 0; i < 500; i++) {
      {
        std::unique_lock<std::mutex> lock(mtx_);
        goods.push(i);
        printf("生产: %d \n", ++count);
        cv_.notify_one();
      }
    }

    std::unique_lock<std::mutex> lock(mtx_);
    done_ = true;
    cv_.notify_one();
  });

  // 消费者
  std::thread consumer([&]() {
    std::unique_lock<std::mutex> lock(mtx_);
    while (!(done_ && goods.empty())) {
      cv_.wait(lock, [&]() { return done_ || !goods.empty(); });
      if (!goods.empty()) {
        goods.pop();
        printf("消耗: %d \n", --count);
      }
    }
  });

  producer.join();
  consumer.join();

  return 0;
}
