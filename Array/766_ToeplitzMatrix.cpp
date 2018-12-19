//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "common_lib.h"

/*
 * 相邻两行，移除第一行末尾、第二行首位，剩下的元素应该完全一致才能成为托普利兹矩阵
 */
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() < 2) {
            return true;
        }
        vector<int> first;
        vector<int> second;
        for (int i = 0; i < matrix.size() - 1; ++i) {
            first = matrix[i];
            first.pop_back();
            second = matrix[i + 1];
            second.erase(second.begin());
            if (first != second) return false;
        }
        return true;
    }
};

/*
 * 第一行、第一列，每个数分别同行、列加1后的数比较，若存在不同则为false
 */
class Solution1 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < col; ++i) {
            int item = matrix[0][i];
            int r = 1, c = i + 1;
            while (r < row && c < col) {
                if (matrix[r][c] != item) return false;
                r += 1;
                c += 1;
            }
        }
        for (int j = 1; j < row; ++j) {
            int item = matrix[j][0];
            int r = j + 1, c = 1;
            while (r < row && c < col) {
                if (matrix[r][c] != item) return false;
                r += 1;
                c += 1;
            }

        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> nums = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    bool result = s.isToeplitzMatrix(nums);
    cout << result << endl;

    return 0;
}


