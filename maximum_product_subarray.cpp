#include<iostream>
#include<vector>
using namespace std;


// Brute force approach - will result in TLE 

class Solution {

    public:

    int maxProduct(vector<int> &nums) {

        int n = nums.size();
        int k = n;
        int maxProd = INT_MIN;
        
        // We check the product of all the sub-arrays and store the max product of those sub-arrays
        while(k > 0) {
            for(int i=0; i<n-k+1; i++) {
                int ans = 1;
                for(int j=i; j<i+k; j++) {
                    ans = ans * nums[j];
                }
                maxProd = max(maxProd, ans);
            }
            k--;
        }

        return maxProd;
    }
};




// Optimized solution

class Solution {

    public:

    int maxProduct(vector<int> &nums) {

        int ans = INT_MIN;
        int curr = 1;

        // We take the product from the left side and right side respectively
        // The idea being - 
        // if the number of negatives are even the product will be positive
        // else if the number of negatives are odd, the negative numbers towards the end will only make the product negative
        // Otherwise the product will be postive

        for(int i=0; i<nums.size(); i++) {
            curr = curr * nums[i];
            ans = max(ans, curr);
            if(curr == 0) {
                curr = 1;
            }
        }

        curr = 1;

        for(int i=nums.size()-1; i>=0; i--) {
            curr = curr * nums[i];
            ans = max(ans, curr);
            if(curr == 0) {
                curr = 1;
            }
        }

        return ans;

    }
};




// Optimmized solution - one pass method

class Solution {

    public:

    int maxProduct(vector<int> &nums) {

        int ans = INT_MIN;
        int n = nums.size();
        int left = 1;
        int right = 1;

        for(int i=0; i<n; i++) {
            left = left * nums[i];
            right = right * nums[n-i-1];
            ans = max(ans, max(left, right));
            if(left == 0) {
                left = 1;
            }
            if(right == 0) {
                right = 1;
            }
        }

        return ans;

    }
};