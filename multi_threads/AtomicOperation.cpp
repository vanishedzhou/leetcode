//
// Created by Zhou,Zhiyong(DAPD) on 2019/1/7.
//

#include "../common_includes.h"
#include "AtomicOperation.h"
#include <time.h>
#include <thread>
#include <mutex>
#include <iostream>

// part1 不加锁 不用原子变量
//long counter = 0;
//void add() {
//    for (int i = 0; i < 1000000; ++i) {
//        counter += 1;
//    }
//}

// part2 加锁
//long counter = 0;
//mutex g_mutex;
//void add() {
//    for (int i = 0; i < 1000000; ++i) {
//        lock_guard<mutex> lock(g_mutex);
//        counter += 1;
//    }
//}

// part3 原子变量
std::atomic<long> counter(0);
void add() {
    for (int i = 0; i < 1000000; ++i) {
        counter += 1;
    }
}

int main(int argc, char *argv[]) {
//    clock_t start = clock();
//    std::cout << start << std::endl;
//
//    vector<thread> threads;
//    for (int i = 0; i < 10; ++i) {
//        threads.push_back(thread(add));
//    }
//
//    for (int j = 0; j < 10; ++j) {
//        threads[j].join();
//    }
//
//    clock_t end = clock();
//    std::cout << "counter:" << counter << " time:" << end-start << std::endl;

    clock_t start = clock();

    vector<thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(thread(add));
    }

    for (int j = 0; j < 10; ++j) {
        threads[j].join();
    }

    clock_t end = clock();
    std::cout << "counter:" << counter << " time:" << end-start << std::endl;

    return 0;
}