#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    vector<vector<int>> res;

    void getPermutations(int i,vector<int> &nums) {

        // Base case
        if(i==nums.size()) {
            res.push_back(nums);
            return;
        }

        // Recursion
        for(int j=i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            getPermutations(i+1, nums);
            swap(nums[j], nums[i]);
        }

 
    }

    vector<vector<int>> permute(vector<int> &nums) {

        getPermutations(0, nums);

        return res;
    }
};