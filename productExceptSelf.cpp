#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> back = vector<int>(nums.size(),1);
        for (int i = 1; i < nums.size(); i++)
        {
            back[i] = (back[i-1] * nums[i-1]);
            
        }
        int lastOne = 1;
        for (int j = nums.size() - 2 ; j >= 0 ;j--)
        {
            lastOne = (lastOne * nums[j+1]);
            back[j] *= lastOne;
        }
        return back;
    }
};

#include<iostream>

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);
    
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}