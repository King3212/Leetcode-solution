#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m+n;
        m = m-1;
        n = n-1;
        for (int _ = 0; _ < size; _++)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[size-1-_] = nums1[m];
                m--;
            }
            else
            {
                nums1[size-1-_] = nums2[n];
                n--;
            }
            
        }
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    
    Solution().merge(nums1, m, nums2, n);
    
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
