//
// Created by Zhou,Zhiyong(DAPD) on 2020/1/19.
//

#include "AtomicFlag.h"
#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>

// atomic_flag变量
// test_and_set, 若被设置则返回true；否则设置该值并返回false
// clear, 重置该变量
std::atomic_flag lock = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_numer(int x)
{
    while (lock.test_and_set());
    stream << "thread#" << x << "\n";
    lock.clear();
}

int main()
{
    std::vector<std::thread> ths;
    for (int i=0; i<10; i++)
        ths.push_back(std::thread(append_numer, i));
    for (int i=0; i<10; i++)
        ths[i].join();
    std::cout << stream.str();
    return 0;
}