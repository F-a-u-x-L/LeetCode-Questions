#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    vector<string> res;

    vector<string> generateParentheses(int n) {

        helper(n, "", 0, 0);
        return res;
    }


    void helper(int n, string str, int open, int close) {
        if(str.length()==2*n) {
            res.push_back(str);
            return;
        }

        if(open<n) {
            helper(n, str+"(", open+1, close);
        }
        if(close<open) {
            helper(n, str+")", open, close+1);
        }
    }
};
