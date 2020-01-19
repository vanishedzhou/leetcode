//
// Created by Zhou,Zhiyong(DAPD) on 2019/2/14.
//
#include "../common_includes.h"
#include <functional>

/*
 * bind 对于原来N个参数的函数，通过bind可定制参数类型如通过占位符或常量改变函数参数,适合用于回调函数。头文件为<functional>
 */

void add(int a, int b) {cout << "a+b:" << a + b << endl;}

class A {
public:
    void minus(int a, int b) {
        std::cout << "a-b:" << a - b << std::endl;
    }
};

int main(int argc, char *argv[]) {
    // 绑定普通函数，_1为占位符
    auto f = std::bind(&add, std::placeholders::_1, 2);
    f(6);
    // 绑定类中成员函数，需指定实例化的对象
    A a;
    auto g = std::bind(&A::minus, &a, std::placeholders::_1, 1);
    g(5);
    return 0;
}

