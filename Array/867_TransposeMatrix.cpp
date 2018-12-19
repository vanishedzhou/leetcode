//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "common_lib.h"


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result;
        vector<int> temp;
        for (int j = 0; j < A[0].size(); ++j) {
            temp.clear();
            for (int i = 0; i < A.size(); ++i) {
                temp.push_back(A[i][j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};

class Solution1 {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result;
        int col = A[0].size();
        for (int i = 0; i < col; ++i) {
            vector<int> item;
            result.push_back(item);
        }
        for (auto iter = A.begin(); iter != A.end(); ++iter) {
            auto& vec = *iter;
            for (int i = 0; i < vec.size(); ++i) {
                result[i].push_back(vec[i]);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> nums = {{1,2,3},{4,5,6}};
    vector<vector<int>> result;
    result = s.transpose(nums);
    for (auto wrap_iter = result.begin(); wrap_iter != result.end(); ++wrap_iter) {
        print_array_tostring(*wrap_iter);
    }

    return 0;
}


