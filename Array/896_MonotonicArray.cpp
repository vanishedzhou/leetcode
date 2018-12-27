//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "common_lib.h"

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool asc = true, desc = true;
        for (int i = 1; i < A.size(); ++i) {
            asc &= A[i] - A[i - 1] >= 0;
            desc &= A[i] - A[i - 1] <= 0;
            if (!asc && !desc) {
                return false;
            }
        }
        return asc || desc;
    }
};

class Solution1 {
public:
    bool isMonotonic(vector<int>& A) {
        int cur = 0;
        bool is_ascent = false;
        while (cur + 1 < A.size() && A[cur] == A[cur + 1]) {
            ++cur;
        }
        if (A[cur + 1] - A[cur] > 0) {
            is_ascent = true;
        }
        while (cur + 1 < A.size()) {
            if (is_ascent && A[cur + 1] - A[cur] < 0) {
                return false;
            }
            if (!is_ascent && A[cur + 1] - A[cur] > 0) {
                return false;
            }
            ++cur;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {-1, 2, 3, 4};
    bool result = s.isMonotonic(nums);
    cout << result << endl;

    return 0;
}


