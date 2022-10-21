#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// Solution using priority queue

class Solution {

    public:

    int findKthLargest(vector<int> &nums, int k) {

        priority_queue<int> q;

        for(int i=0; i<nums.size(); i++) {
            q.push(nums[i]);
        }

        while(k>1) {
            q.pop();
            k--;
        }

        return q.top();
    }
};


// Solution using STL n-th element  -   Time Complexity O(N)

// nth_element() is an STL algorithm which rearranges the list in such a way such that the element at the nth position 
// is the one which should be at that position if we sort the list.

class Solution {

    public:

    int findKthLargest(vector<int> &nums, int k) {
        
        nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
        return nums[nums.size() - k];

        for(int i=0; i<k; i++) {
            cout<<nums[i]<<" ";
        }
    }

};


class Solution {

    public:

    int findKthLargest(vector<int> &nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k-1];
    }
};



// Solution using STL partial_sort

// It rearranges the elements in the range [first, last), in such a way that the elements before middle are sorted in ascending order, 
// whereas the elements after middle are left without any specific order.

class Solution {

    public:

    int findKthLargest(vector<int> &nums, int k) {
        partial_sort(nums.begin(), nums.begin() + nums.size() - k + 1, nums.end());
        return nums[nums.size() - k];
    }
};


class Solution {

    public:

    int findKthLargest(vector<int> &nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k-1];
    }
};