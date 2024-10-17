#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while(j < nums.size()){
            if(nums[j] > nums[i]){
                i++;
                nums[i] = nums[j];
            }else if(nums[j] == nums[i] && ( i == 0 || nums[j] != nums[i-1])){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution s;
    int len = s.removeDuplicates(nums);
    cout << len << endl;
    for(int i = 0; i < len; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}