//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "common_lib.h"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cur = 0;
        bool changed = false;
        while (cur < nums.size() - 1) {
            if (nums[cur + 1] < nums[cur]) {
                if (!changed) {
                    nums[cur] = nums[cur + 1];
                } else {
                    return false;
                }
                changed = true;
            }
            ++cur;
        }
        return true;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {4,2,3};
    bool result = s.checkPossibility(nums);
    cout << result << endl;

    return 0;
}


