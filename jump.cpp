#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minToLoc(nums.size(),-1);
        return findMin(nums.size()-1,nums,minToLoc);
    }

    int findMin(int loc,vector<int>& nums,vector<int>& minToLoc){
        if(minToLoc[loc] != -1){
            return minToLoc[loc];
        }
        int mintmp = 0;
        for (int i = 0; i < loc; i++)
        {
            if (i + nums[i] >= loc) 
            {
                if(mintmp == 0){
                    mintmp = findMin(i, nums, minToLoc) + 1;
                }else{
                    mintmp = min(mintmp, findMin(i,nums,minToLoc)+1);
                }
            }
            
        }
        minToLoc[loc] = mintmp;
        return mintmp;
    }
};

#include<iostream>

int main(){
    vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    Solution s;
    int res = s.jump(nums);
    cout << res << endl;
    return 0;
}