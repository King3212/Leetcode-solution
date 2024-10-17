#include<vector>
#include<cmath>
using namespace std;
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int maxOne = 0,minOne = 0;
        int maxPrice= prices[0], minPrice = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
                minOne = i;
            }else if(prices[i] > maxPrice){
                maxPrice = prices[i];
                maxOne = i;
            }
        }
        if(maxOne >= minOne) return maxPrice-minPrice;
        else{
            if(maxOne+1 == minOne) return max(findMax(prices,minOne),findMin(prices,maxOne));
            vector<int> mid(prices.begin() + maxOne +1, prices.begin() + minOne);
            return max(max(findMax(prices,minOne),maxProfit(mid)),findMin(prices,maxOne));
        }
    }
    int findMin(vector<int>& prices,int maxOne){
        int minPrice = prices[0];
        for (int i = 0; i <= maxOne; i++)
        {
            minPrice = min(prices[i],minPrice);
        }
        return prices[maxOne] - minPrice;
    }
    int findMax(vector<int>& prices,int minOne){
        int maxPrice = prices[minOne];
        for (int i = minOne; i < prices.size(); i++)
        {
            maxPrice = max(prices[i],maxPrice);
        }
        return maxPrice - prices[minOne];
    
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 0;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(prices[i],minPrice);
            maxProfit = max(prices[i] - minPrice,maxProfit);
            
        }
        return maxProfit;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    vector<int> prices = {7, 2,4,1};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl; // 输出应为 5

    prices = {7, 6, 4, 3, 1};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl; // 输出应为 0

    return 0;
}