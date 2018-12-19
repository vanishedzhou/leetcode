//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/17.
//
#include "common_lib.h"

/*
 * 两种错位case：奇数位是偶数、偶数位是奇数，且二者数量一致。分别两个指针遍历，相互交换即可
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even_idx = 0;
        int odd_idx = 1;
        int last_even_idx = (A.size() - 1) % 2 == 0 ? A.size() - 1 : A.size() - 2;
        int last_odd_idx = (A.size() - 1) % 2 == 1 ? A.size() - 1 : A.size() - 2;
        while (even_idx <= last_even_idx) {
            while (even_idx <= last_even_idx && A[even_idx] % 2 == 0) even_idx += 2;
            while (odd_idx <= last_odd_idx && A[odd_idx] % 2 == 1) odd_idx += 2;
            if (even_idx <= last_even_idx) {
                int temp = A[even_idx];
                A[even_idx] = A[odd_idx];
                A[odd_idx] = temp;
            }
        }
        return A;
    }
};

class Solution1 {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even_idx = 0;
        int odd_idx = (A.size() - 1) % 2 == 1 ? A.size() - 1 : A.size() - 2;
        while (odd_idx > 0) {
            while (even_idx < A.size() && A[even_idx] % 2 == 0) even_idx += 2;
            while (odd_idx > 0 && A[odd_idx] % 2 == 1) odd_idx -= 2;
            if (odd_idx > 0) {
                int temp = A[even_idx];
                A[even_idx] = A[odd_idx];
                A[odd_idx] = temp;
            }
        }
        return A;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {4,2,5,7};
    s.sortArrayByParityII(nums);
    print_array_tostring(nums);

    return 0;
}


