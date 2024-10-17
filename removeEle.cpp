#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int i = nums.size()-1;
        for(auto &ele : nums){
            if(ele == val) k++;
            while (ele == val){
                ele = nums[i];
                i--;
            }
        }
        return k;
    }
};