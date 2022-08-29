#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    bool canJump(vector<int> &nums) {

        int minjump = 0;

        for(int i=nums.size()-2; i>=0; i--) {
            minjump++;
            if(nums[i] >= minjump) {
                minjump = 0;
            }
        }

        if(minjump == 0) {
            return true;
        }

        return false;
    }
};