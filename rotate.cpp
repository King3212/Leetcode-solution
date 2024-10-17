#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
        {
            rotate1(nums);
        }
        
    }

    void rotate1(vector<int>& nums) {
        int temp = nums[nums.size()-1];
        for (int i = nums.size() -1; i > 0; i--)
        {
            nums[i] = nums[(i-1)%nums.size()];
        }
        nums[0] = temp;
        
    }
};