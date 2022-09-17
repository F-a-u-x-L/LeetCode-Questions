#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    int getSum(int a, int b) {

        // (a & b) << 1 : this operation is done to generate the carry
        // eg: only (1 + 1) generate a carry and if we do (1 & 1) << 1  : we get 10, which acts as the carry

        // (a ^ b) gives the sum of two number ignoring the carry

        // We run the loop till the carry becomes zero
        while(b) {
            int temp = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = temp;
        }

        return a;
    }
};