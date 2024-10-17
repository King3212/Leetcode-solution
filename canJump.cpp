#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0];
        int start = 0;
        bool hasChange = 1;
        while (maxReach < nums.size()-1 && hasChange)
        {
            hasChange = 0;
            for (int i = start; i <= maxReach; i++)
            {
                start = i;
                if(i+nums[i] > maxReach){
                    maxReach = i+nums[i];
                    hasChange = true;
                    break;
                }
                
            }
            
        }
        if (maxReach >= nums.size() - 1)
        {
            return true;
        }
        
        return false;
    }
};

#include<iostream>


int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution s;
    bool res = s.canJump(nums);
    cout << res << endl;
    return 0;
}