#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {

    public:

    vector<vector<int>> threeSum(vector<int> &nums) {

        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n<3) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++) {

            // The moment nums[i] becomes positive, we break the loop because now the sum can never be zero
            if(nums[i] > 0) break;

            // We do this to avoid repetition as we would have already checked cases for that element
            if(i>0 && nums[i]==nums[i-1]) continue;

            // Initializing the two pointers
            int start = i+1;
            int end = n-1;

            int sum = 0;

            while(start<end) {
                sum = nums[i] + nums[start] + nums[end];

                if(sum>0) {
                    end--;
                    // Beacuse we will be needing a smaller positive value to make sum = 0
                }
                else if (sum<0) {
                    start++;
                    // Because we will be needing a smaller negative value to make sum = 0
                }
                else {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    int prevStart = nums[start];
                    int prevEnd = nums[end];

                    // To make sure that the triplets are not repeated
                    while(start<end && nums[start]==prevStart) {
                        start++;
                    }
                    while(start<end && nums[end]==prevEnd) {
                        end--;
                    }
                }
            }
        }

        return ans;
    }
};