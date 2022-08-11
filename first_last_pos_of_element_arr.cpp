#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    vector<int> searchRange(vector<int> &nums, int target) {

        vector<int> ans{-1, -1};
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start <= end) {
            mid = (start + end) / 2;

            if(nums[mid] == target) {

                start = mid;
                end = mid;

                while(start>=0 && nums[start] == target) {
                    ans[0] = start;
                    start--;
                }

                while(end<nums.size() && nums[end] == target) {
                    ans[1] = end;
                    end++;
                }

                return ans;
            }

            if(nums[mid] >  target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};