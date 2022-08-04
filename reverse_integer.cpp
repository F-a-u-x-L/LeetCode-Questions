#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Alternate solution, without using long int
// INT_MAX = 2147483647
// INT_MIN = -2147483648

class Solution {

    public:

    int reverse(int x) {

        int ans =  0;

        while(x != 0) {
            int rem = x % 10;
            x /= 10;

            // Check if ans is greater than INT_MAX/10, if so then it will exceed the 32 bit range in next iteration
            if(ans > INT_MAX/10 || ( ans == INT_MAX/10 && rem > 7)) {
                return 0;
            }
            // Check if ans is smaller than INT_MIN/10, if so then it will exceed the 32 bit range in next iteration
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && rem < -8)) {
                return 0;
            }

            ans = ans*10 + rem;
        }

        return ans;
    }
};