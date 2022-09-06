#include<iostream>
#include<vector>
using namespace std;



// To find subsets, we need to use back-tracking

class Solution {

    public:

    vector<vector<int>> res;

    void helper(vector<int> &nums, int i, vector<int> &ans) {

        // Base Case
        if(i == nums.size()) {
            res.push_back(ans);
            return;
        }

        // Backtracking
        ans.push_back(nums[i]);
        helper(nums, i+1, ans);
        ans.pop_back();
        helper(nums, i+1, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        
        vector<int> ans;
        helper(nums, 0, ans);

        return res;
    }
};