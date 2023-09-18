#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

/**
 * 设置回调A----> B----->C------->D
 */

class D {
 public:
  void OnError(std::function<void(int errCode)> onError) {
    on_error_ = onError;

    // 休眠1s
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    on_error_(-1);
  }

 private:
  std::function<void(int errCode)> on_error_;
};

class C {
 public:
  C() { d_ = new D(); }
  ~C() { delete d_; }
  void OnError(std::function<void(int errCode)> onError) {
    d_->OnError(onError);
  }

 private:
  D* d_;
};

class B {
 public:
  B() { c_ = new C(); }
  ~B() { delete c_; }
  void OnError(std::function<void(int errCode)> onError) {
    c_->OnError(onError);
  }

 private:
  C* c_;
};

class A {
 public:
  A() { b_ = new B(); }
  ~A() { delete b_; }

  void SetErrorCallback() {
    b_->OnError([this](int errCode) {
      printf("======== Error Code: %d =========\n", errCode);
    });
  }

 private:
  B* b_;
};

int main(int argc, char* argv[]) {
  A* a = new A();
  a->SetErrorCallback();
  return 0;
}