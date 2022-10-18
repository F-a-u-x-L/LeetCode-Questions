#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Brute force solution, results in TLE

class Solution {

    public:

    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        int temp;

        while(k>0) {
            for(int i=0; i<n-1; i++) {
                temp = nums[i+1];
                nums[i+1] = nums[0];
                nums[0] = temp;
            }
            k--;
        }
    }
};


// Using O(K) space and O(N) time complexity

class Solution {

    public:

    void rotate(vector<int> &nums, int k) {

        int n = nums.size();
        k = k % n;
        vector<int> arr(k,0);

        for(int i=0; i<k; i++) {
            arr[i] = nums[n-k+i];
        }

        for(int i=0; i<n-k; i++) {
            arr.push_back(nums[i]);
        }

        for(int i=0; i<n; i++) {
            nums[i] = arr[i];
        }
    }
};


// Using O(N) time complexity and O(1) space complexity

class Solution {

    public:

    void rotate(vector<int> &nums, int k) {

        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

