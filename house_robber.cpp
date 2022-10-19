#include<iostream>
#include<vector>
using namespace std;


// Memoization

class Solution {

    public:

    int rec(vector<int> &nums, int idx, vector<int> dp) {

        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        return dp[idx] = max(nums[idx] + rec(nums, idx+2, dp), rec(nums, idx+1, dp));
    }

    int rob(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, -1);

        return rec(nums, 0, dp);
    }
};



// Dynamic Programming

class Solution {

    public:

    int rob(vector<int> &nums){
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.size() - 1];
    }
};



// Optimized Dynamic Programming - space complexity O(1)

class Solution {

    public:

    int rob(vector<int> &nums) {

        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }

        int prev_ans2 = nums[0];
        int prev_ans = max(nums[0], nums[1]);
        int curr_ans = prev_ans;

        for(int i=2; i<n; i++) {
            curr_ans = max(prev_ans, prev_ans2 + nums[i]);
            prev_ans2 = prev_ans;
            prev_ans =curr_ans;
        }

        return curr_ans;
    }
};