#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


// Time complexity O(N^2)   ->  results in TLE

class Solution {

    public:

    int findDuplicate(vector<int> &nums) {

        int n = nums.size();

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {

                if(sqrt(nums[i]*nums[j]) == nums[i]) {
                    return nums[i];
                }
            }
        }

        return 0;
    }
};


class Solution {

    public:

    int findDuplicate(vector<int> &nums) {

        int n = nums.size();

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {

                if(nums[j] == nums[i]) {
                    return nums[i];
                }
            }
        }

        return 0;
    }
};



// Negative Marking Approach - time complexity O(N) and space complexity O(1)

class Solution {

    public:

    int findDuplicate(vector<int> &nums) {

        int n = nums.size();
        int duplicate;

        for(int i=0; i<n; i++) {
            int index = abs(nums[i]);

            if(nums[index] < 0) {
                // This works because there is only one duplicate, thus apart from the duplicate number,
                // all the numbers will be visited only once and should be positive initially
                // If nums[index] is found to be negative that means that it was visited before by the same index
                // Thus, index is the duplicate number
                duplicate = abs(nums[i]);
            }
            nums[index] *= -1;
        }

        for(int i=0; i<n; i++) {
            nums[i] = abs(nums[i]);
        }

        return duplicate;
    }
};



// Floyd's Algorithm    ->  Tortoise and Hare logic

class Solution {

    public:

    int findDuplicate(vector<int> &nums) {
        
        int tortoise = nums[0];
        int hare = nums[0];

        // Finding the intersection of two numbers
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while(tortoise != hare);

        // Finding the entrance of cycle
        tortoise = nums[0];
        while( tortoise != hare ) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};