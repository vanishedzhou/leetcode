//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "../common_lib.h"

/*
 * 找规律，原理是对称交换后取反。若相同则同时取反，不同则交换取反后保持不变
 */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto iter = A.begin(); iter != A.end(); ++iter) {
            auto& item = *iter;
            int left = 0;
            int right = item.size() - 1;
            while (left < right) {
                if (item[left] == item[right]) {
                    int temp = (item[left] + 1) % 2;
                    item[left] = temp;
                    item[right] = temp;
                }
                ++left;
                --right;
            }
            if (left == right) {
                item[left] = (item[left] + 1) % 2;
            }
        }

        return A;
    }
};

class Solution2 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto iter = A.begin(); iter != A.end(); ++iter) {
            auto& item = *iter;
            int left = 0;
            int right = item.size() - 1;
            while (left < right) {
                if (item[left] == item[right]) {
                    int temp = item[left] ^ 1;
                    item[left] = temp;
                    item[right] = temp;
                }
                ++left;
                --right;
            }
            if (left == right) {
                item[left] = item[left] ^ 1;
            }
        }

        return A;
    }
};

class Solution1 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto iter = A.begin(); iter != A.end(); ++iter) {
            auto& vec = *iter;
            int left = 0;
            int right = vec.size() - 1;
            while (left < right) {
                int temp = vec[left];
                vec[left] = (vec[right] ^ 1);
                vec[right] = (temp ^ 1);
                ++left;
                --right;
            }
            if (left == right) {
                vec[left] = (vec[left] ^ 1);
            }
        }
        return A;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> A = {{1,1,0},{1,0,1},{0,0,0}};
    s.flipAndInvertImage(A);
    for (auto wrap_iter = A.begin(); wrap_iter != A.end(); ++wrap_iter) {
        print_array_tostring(*wrap_iter);
    }

    return 0;
}


