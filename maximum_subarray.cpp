#include<iostream>
#include<vector>
using namespace std;


// Brute Force Method

class Solution {

    public:

    int maxSubArray(vector<int> &nums){
        
        int maxSum = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            int currSum = 0;
            for(int j=i; j<nums.size(); j++) {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};



// Kadane's Algorithm

class Solution {

    public:

    int maxSubArray(vector<int> &nums) {

        int maxSum = INT_MIN;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};