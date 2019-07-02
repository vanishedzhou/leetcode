//
// Created by Zhou,Zhiyong(DAPD) on 2018/11/28.
//

#ifndef UNTITLED_COMMON_LIB_H
#define UNTITLED_COMMON_LIB_H

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

static void print_array_tostring(const vector<int>& nums) {
    string conc = "";
    for (vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
        conc += " ";
        conc += to_string(*iter);
    }
    cout << conc << endl;
}

#endif //UNTITLED_COMMON_LIB_H
