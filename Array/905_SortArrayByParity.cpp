//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "../common_lib.h"

/*
 * 前后向中间移动，判断奇数偶数，相互交换
 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        while (left < right) {
            while (left < right && A[left] % 2 == 0) ++left;
            while (left < right && A[right] %2 == 1) --right;
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
        }
        return A;
    }
};

class Solution1 {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even_vec, odd_vec;
        for (auto wrap_iter = A.begin(); wrap_iter != A.end(); ++wrap_iter) {
            if (*wrap_iter % 2 == 0) {
                even_vec.push_back(*wrap_iter);
            } else {
                odd_vec.push_back(*wrap_iter);
            }
        }
        vector<int> result;
        for (auto iter = even_vec.begin(); iter != even_vec.end(); ++iter) {
            result.push_back(*iter);
        }
        for (auto wrapIter = odd_vec.begin(); wrapIter != odd_vec.end(); ++wrapIter) {
            result.push_back(*wrapIter);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3,1,2,4};
    nums = s.sortArrayByParity(nums);
    print_array_tostring(nums);

    return 0;
}


