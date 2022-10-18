#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Using custom comparator

bool compare(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1+s2 > s2+s1;
}

class Solution {

    public:

    string largestNumber(vector<int> &nums) {

        sort(nums.begin(), nums.end(), compare);
        string ans;

        for(int i=0; i<nums.size(); i++) {
            ans += to_string(nums[i]);
        }

        return ans[0]=='0' ? "0" : ans;
    }
};