//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/26.
//
#include <iostream>

class Person {
public:
    Person (char* name) {
        std::cout << "Person basic constructor function, name:" << name << std::endl;
        _name = new char[strlen(name) + 1];
        if (_name != NULL) {
            strcpy(_name, name);
        }
    }
//
//    // wrong，拷贝构造函数使指针成员变量指向被拷贝对象成员的同一地址，分别析构会异常
//    Person (Person& p) {
//        _name = p._name;
//    }

    // right，类似于自己实现了"深拷贝"，重新申请了内存空间复制了字符串
    Person (Person& pp) {
        std::cout << "Person copy constructor function, name:" << pp._name << std::endl;
        _name = new char[strlen(pp._name) + 1];
        if (_name) {
            strcpy(_name, pp._name);
        }
    }

    ~Person () {
        delete _name;
    }

private:
    char* _name;
};

int main(int argc, char *argv[]) {
    Person man("adam");
    Person woman(man);

    return 0;
}