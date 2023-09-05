#include <memory>
#include <chrono>
#include <iostream>

using namespace std::chrono;

void shared_ptr_receiver_by_value(std::shared_ptr<int> ptr) {
    (void)*ptr;
}

void shared_ptr_receiver_by_ref(const std::shared_ptr<int>& ptr) {
    (void)*ptr;
}

void test_copy_by_value(uint64_t n) {
    auto ptr = std::make_shared<int>(100);
    for(uint64_t i = 0u; i < n; ++i) {
        shared_ptr_receiver_by_value(ptr);
    }
}

void test_copy_by_ref(uint64_t n) {
    auto ptr = std::make_shared<int>(100);
    for(uint64_t i = 0u; i < n; ++i) {
        shared_ptr_receiver_by_ref(ptr);
    }
}

int main(int argc, char *argv[]) {
	int count = 1000000;
    auto t1 = high_resolution_clock::now();
    test_copy_by_value(count);
    auto t2 = high_resolution_clock::now();
    auto time_span = duration_cast<duration<int64_t, std::micro>>(t2 - t1);
    std::cout << "Shared_ptr Copy By Value 1000000 times ,It took me " << time_span.count() << " microseconds.\n";

    printf("===================================\n");


    auto t3 = high_resolution_clock::now();
    test_copy_by_ref(count);
    auto t4 = high_resolution_clock::now();
    auto time_span2 = duration_cast<duration<int64_t, std::micro>>(t4 - t3);
    std::cout << "Shared_ptr Copy By Ref 1000000 times ,It took me " << time_span2.count() << " microseconds.\n";


    return 0;
}