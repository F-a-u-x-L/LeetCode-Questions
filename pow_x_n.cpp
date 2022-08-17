#include<iostream>
#include<vector>
using namespace std;


// Inefficient Way
class Solution {

    public:

    double helper(double x, int n) {
        // Base case
        if(n==0) {
            return 1;
        }

        return helper(x, n-1) * x;
    }

    double myPow(double x, int n) {

        if(n == 0) {
            return 1;
        }

        double ans;
        int m = abs(n);

        ans = helper(x, m);

        return n>0 ? ans : 1/ans;
    }
};


// Using binary exponentiation

// In order to improve efficiency we will opt for Binary Exponentiation using which we can calculate xn using O log2(N) multiplications.

// Basic Idea is to divide the work using binary representation of exponents
// i.e. is to keep multiplying pow with x, if the bit is odd, and multiplying x with itself until we get 0
// We will use very 1st example of 1st Approach i.e.
// x = 7, n = 11 and pow = 1
// Here, we have to calculate 711
// Binary of n i.e. (11)10 is (1011)2
//  1    0    1    1
// 2^3  2^2  2^1  2^0   <-- Corresponding place values of each bit

// OR we can also write this as
// 1 0 1 1
// 8 4 2 1 <-- Corresponding place values of each bit

// Now, 7^8 × 7^2 × 7^1 == 7^11 as 7^(8 + 2 + 1) == 7^11
// NOTE: We have not considered 74 in this case as the 4th place bit is OFF

// So, 78 × 72 × 71 == 5764801 × 49 × 7 == 1977326743 <-- Desired Output

class Solution {

    public:

    double myPow(double x, int n) {
        
        // If negative power, we inverse x
        if(n<0) {
            x = 1/x;
        }

        // absolute value of long
        long num = labs(n);
        double pow = 1;

        while(num != 0) {
            if(num & 1 != 0) {
                pow *= x;
            }

            x *= x;
            num = num >> 1;
        }

        return pow;
    }
};