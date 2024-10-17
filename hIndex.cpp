#include<vector>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1){
            if(citations[0] == 0){
                return 0;
            }else{
                return 1;
            }
        }else if(citations.size() == 0){
            return 0;
        }
        
        sort(citations.begin(),citations.end());
        int size = citations.size();
        for (int i = 1; i <= size; i++)
        {
            if(i > citations[size- i]){
                return i -1;
            }
        }
        return 0;
    }
};
#include<iostream>
int main(){
    vector<int> citations = {1,3,1};
    Solution s;
    int res = s.hIndex(citations);
    cout << res << endl;
    return 0;
}