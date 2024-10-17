#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x;
        while(true){
            x = nums[rand() % nums.size()];
            int count = 0;
            for(auto &ele : nums){
                if(ele == x) count++;
            }
            if(count > nums.size()/2) return x;
        }

    }
};