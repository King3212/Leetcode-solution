#include <math.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31
        // 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30
        if(red < blue){
            red = red + blue;
            blue = red - blue;
            red = red - blue;
        }//red > blue

        // if last row % 2 == 0
        //red = 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,...
        // red >= 2+4+...+2n = n(n+1)
        //blue = 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,...
        // blue >= 1+3+...+2n-1 = n^2
        int n1 = int(sqrt(blue));
        while (n1*(n1+1) > red)
        {
            n1--;
        }
        n1 = 2*n1;
        // if last row % 2 == 1
        // red = 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,...
        // red >= 1+3+...+2n-1 = n^2
        // blue = 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,...
        // blue >= 2+4+...+2n-2 = n(n-1)
        int n2 = int(sqrt(red));
        while (n2*(n2-1) > blue)
        {
            n2--;
        }
        n2 = 2*n2-1;

        return max(n1,n2);
    }
};

int main()
{
    Solution s;
    cout << s.maxHeightOfTriangle(10,1) << endl;
}