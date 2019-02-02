//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/29.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Utils {
public:
    template <typename T>
    static void print_vector_elems(const std::vector<T>& vec, const std::string& comment = "") {
        std::ostringstream oss;
        for (auto iterator = vec.begin(); iterator != vec.end(); ++iterator) {
            oss << *iterator << " ";
        }
        std::cout << comment << " : " << oss.str();
    }
};

#endif //UNTITLED_UTILS_H
