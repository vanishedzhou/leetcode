//
// Created by Zhou,Zhiyong(DAPD) on 2019/2/14.
//
#include "../common_includes.h"
#include <functional>

/*
 * 可变模板参数...用法
 */

// 递归打印可变参数args
void add()
{
}

template <typename T, typename ...args>
void add(T a, args... b)
{
    cout << "a:" << a << endl;
    cout << sizeof...(b) << endl;
    add(b...);
}

class A {
public:
    void minus(int a, int b) {
        std::cout << "a-b:" << a - b << std::endl;
    }
};

int main(int argc, char *argv[]) {
    add(1,2,3,4);
    add("a", "b", "c");
}

