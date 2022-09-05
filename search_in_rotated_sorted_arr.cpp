#include<iostream>
#include<vector>
using namespace std;


class Solution {

    public:

    int search(vector<int> &nums, int target) 
    {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid;

        while( start<=end ) 
        {

            mid = (start + end) / 2;

            if(nums[mid] == target) 
            {
                return mid;
            }

            // Here we check which part of the array is sorted ie before mid part or after mid part
            // Then we check if the target element lies within that selected sorted part or not
            // We adjust the start/end accordingly 
            if(nums[start] < nums[mid]) 
            {
                if(target < nums[mid] && target >= nums[start]) 
                {
                    end = mid - 1;
                }
                else 
                {
                    start = mid + 1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};