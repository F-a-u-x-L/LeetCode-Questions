#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    int findPeakElement(vector<int> &nums) {
        int n = nums.size();

        if(n==1) {
            return 0;
        }

        if(n==2) {
            return nums[0]>nums[1] ? 0 : 1;
        }

        int i = 1;

        while(i<n-1) {
            int mid = nums[i];
            int left = nums[i-1];
            int right = nums[i+1];

            if(mid>left && mid>right) {
                return i;
            }
            if(mid<left && mid>right) {
                i+=2;
                continue;
            }

            i++;
        }

        return nums[0] > nums[n-1] ? 0 : n-1;
    }
};



// USING Binary Search algorithm

class Solution {

    public:

    int findPeakElement(vector<int> &nums) {

        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {
            int mid = (start + end) / 2;

            if(nums[mid] > nums[mid+1]) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }
};