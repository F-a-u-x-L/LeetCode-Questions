#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {

    public:

    vector<vector<int>> merge(vector<vector<int>> &intervals) {

        // We sort the intervals array so that the first element of eac vector is arranged in increasing order
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        // Define a vector of size two, which will hold the value of the merged interval such that
        // ans[0] - start of an interval, ans[1] - end of the interval depending on whether intervals are merged of not
        vector<int> ans(2,0);
        ans[0] = intervals[0][0];
        ans[1] = intervals[0][1];

        for(int i=1; i<intervals.size(); i++) {

            // If ans[1] is greater than or equal to the start of current interval, it means that the intervals can be merged
            // Otherwise we push and into the result and update the values of ans by assigning the current interval values
            if(ans[1] >= intervals[i][0]) {
                ans[1] = max(intervals[i][1], ans[1]);
            } 
            else {
                res.push_back(ans);
                ans[0] = intervals[i][0];
                ans[1] = intervals[i][1];  
            }
        }

        res.push_back(ans);

        return res;
    }
};