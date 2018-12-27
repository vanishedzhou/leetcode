//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/18.
//

#include "multi_thread.h"
#include "thread"

void say_hello() {
    for (int i = 0; i < 100; ++i) {
        std::cout << "zzy hello !" << "this is num " << i << std::endl;
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i) {
        std::thread t(say_hello);
        t.join();
    }

    std::cout << "main ended !" << std::endl;
    return 0;
}
