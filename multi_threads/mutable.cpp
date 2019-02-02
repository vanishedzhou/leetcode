//
// Created by Zhou,Zhiyong(DAPD) on 2019/1/25.
//

#include "../common_includes.h"

class Test {
public:
    Test() {
        count = 0;
    }

    void output() const{
        cout << "test output" << endl;
        //const函数也能修改变量,默认是不能修改普通变量的
        count++;
    }

    void getCount() const {
        std::cout << count << std::endl;
    }

private:
    // mutable使得被const修饰的函数也能修改类中成员变量
    mutable int count;
    // 不能被const修饰的函数修改
    int ano_count;
};

class another {
public:
    void ano_output() {
        Test t;
        t.getCount();
        t.output();
        t.getCount();
    }
};

int main(int argc, char *argv[]) {
    another ano;
    ano.ano_output();

    return 0;
}