#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {

    public:

    int longestConsecutive(vector<int> &nums) {

        // Inserting all the elements into the unordered set
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for(auto num : s) {
            int curr_longest = 1;

            // Finding consecutive elements in the backward and forward direnction from num
            for(int j=1; s.count(num - j); j++) {
                s.erase(num-j);
                curr_longest++;
            }
            for(int j=1; s.count(num + j); j++) {
                s.erase(num + j);
                curr_longest++;
            }

            longest = max(longest, curr_longest);
        }

        return longest;
    }
};