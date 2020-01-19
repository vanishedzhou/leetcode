//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/18.
//

#include "multi_thread.h"
#include "thread"

void say_num(int& n) {
    std::cout << "thread num:" << n << std::endl;
    ++n;
    std::chrono::milliseconds duration(2000);
    std::this_thread::sleep_for(duration);
}

void say_noref(int n) {
    std::cout << "thread:" << n << " id:" << std::this_thread::get_id() << std::endl;
    std::chrono::milliseconds duration(100);
    std::this_thread::sleep_for(duration);
}

void say_hello() {
    std::chrono::milliseconds duration(1000);
    for (int i = 0; i < 10; ++i) {
        std::cout << "this is num " << i << std::endl;
        // 线程等待xx时间
//        std::this_thread::sleep_for(duration);
    }
}

void long_thread() {
    for (int i = 0; i < 10; ++i) {
        std::chrono::milliseconds duration(1000);
        std::cout << "long thread : " << i << std::endl;
        std::this_thread::sleep_for(duration);
    }
}

void short_thread(int i) {
    std::cout << "short thread : " << i << std::endl;
}

int main(int argc, char *argv[]) {
    // join主线程等待子线程结束，detach则子线程离开主线程不和主线程通信(此处不会继续打印后续数字在终端)
//    for (int i = 0; i < 10; ++i) {
//        std::thread t(say_hello);
//        t.join();
//        t.detach();
//    }

//    // 初始化线程调用函数参数,ref使用引用传递参数
//    int n = 1;
//    std::cout << "before n:" << n << std::endl;
//    std::thread t1;
//    std::thread t2(say_num, ref(n));
//    t2.join();
//    std::cout << "after n:" << n << std::endl;

//    // 线程数组
//    std::thread t_list[3];
//    for (int i = 0; i < 3; ++i) {
//        t_list[i] = std::thread(say_noref, i + 1);
//    }
//    for (auto& t : t_list) {
//        // 线程可通过joinable判断是否是活动线程（包括已执行完的线程）
//        if (t.joinable()) {
//            std::cout << "is joinable" << std::endl;
//        }
//        t.join();
//    }
//    for (int i = 0; i < sizeof(t_list); ++i) {
//        t_list[i].join();
//    }

    // 测试多个join是否依次等待执行
    std::cout << "before t1 t2 define" << std::endl;
    std::thread t1(long_thread);
    std::cout << "after t1 define" << std::endl;
    std::thread t2(short_thread, 999);
    std::cout << "after t2 define" << std::endl;

    std::cout << "before t1 join" << std::endl;
    t1.join();
    std::cout << "after t1 join" << std::endl;
    t2.join();
    std::cout << "after t2 join" << std::endl;

    std::cout << "main ended !" << std::endl;
    return 0;
}
