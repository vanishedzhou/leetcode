//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "common_lib.h"

/*
 * sort；最大的sum肯定是从index=0每隔两个相加
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i+=2) {
           sum += nums[i];
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,4,3,2};
    int result = s.arrayPairSum(nums);
    cout << result << endl;

    return 0;
}


