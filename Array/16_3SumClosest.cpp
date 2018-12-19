//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/6.
//
#include "common_lib.h"

/*
 * 先sort；设三个指针，1遍历，3固定最后一个位置，2在1之后；判断累加值大于target则3后移，否则2前移
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int final_three_sum = 0;
        int minus_value = INT_MAX;
        int left = 0;
        for (left = 0; left < nums.size() - 2; ++left) {
            if (left > 0 && nums[left-1] == nums[left]) continue;
            int mid = left + 1;
            int right = nums.size() - 1;
            while (mid < right) {
                int tmp_three_sum = nums[left] + nums[right] + nums[mid];
                int tmp_minus = tmp_three_sum - target;
                if (abs(tmp_minus) < abs(minus_value)) {
                    minus_value = tmp_minus;
                    final_three_sum = tmp_three_sum;
                }
                if (tmp_minus > 0) {
                    --right;
                } else if (tmp_minus < 0) {
                    ++mid;
                } else {
                    return target;
                }
            }
        }
        return final_three_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    //vector<int> nums = {-1, 2, 1, -4};
    //int target = 1;
    //vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    //int target = -2;
    vector<int> nums = {1,1,1,1};
    int target = 0;

    sort(nums.begin(), nums.end());
    print_array_tostring(nums);

    int result = s.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}
