//
// Created by Zhou,Zhiyong(DAPD) on 2018/11/28.
//
#include "../common_lib.h"

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int max_area_record = 0;
        int n = height.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                int min_h = min(height[j], height[j+i]);
                if (min_h*i > max_area_record) {
                    max_area_record = min_h*i;
                }
            }
        }
        return max_area_record;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area_record = 0;
        int n = height.size();
        int low = 0, high = n-1;
        while (low < high) {
            max_area_record = max(max_area_record, (high - low) * min(height[low], height[high]));
            if (height[low] < height[high]) {
                ++low;
            } else {
                --high;
            }
        }
        return max_area_record;
    }
};

int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int max_h = s.maxArea(height);
    cout << max_h << endl;

    return 0;
}