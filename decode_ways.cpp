#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {

    public:

    int count = 0;

    void helper(string &s, int index) {

        // Base Case
        if(index > s.length() - 1) {
            count++;
            return;
        }

        string str;
        str += s[index];

        if(stoi(str) > 0 && stoi(str) < 27) {
            helper(s, index+1);
            if(index+1 < s.length()) {
                str += s[index+1];
                if(stoi(str) > 0 && stoi(str) < 27) {
                    helper(s, index+2);
                }
            }
        } else {
            return;
        }
    }

    int numDecodings(string s) {

        if(s[0] == '0') {
            return 0;
        }

        helper(s, 0);

        return count;
    }
};


// Alternate recursion - gives TLE as well

class Solution {

    public:

    int decode(string &s, int index, int n) {

        if(index<n && s[index]=='0') {
            return 0;
        }

        if(index >= n) {
            return 1;
        }

        int ways = 0;

        // Pick single element
        if(s[index] != '0'){
            ways = decode(s, index+1, n);
        }

        // Pick two elements
        if(index+1<n && ((s[index]=='1' && s[index+1]<='9') || (s[index]=='2' && s[index+1]<='7'))){
            ways += decode(s, index+2, n);
        }

        return ways;
    }

    int numDecodings(string s) {

        int n = s.size();
        return decode(s, 0, n);
    }
};



// Memoization

class Solution {

    public:

    int dp[102];

    int decode(string &s, int index, int n) {

        if(index<n && s[index]=='0') {
            return 0;
        }

        if(index >= n) {
            return 1;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        int ways = 0;

        // Pick single element
        if(s[index] != '0'){
            ways = decode(s, index+1, n);
        }

        // Pick two elements
        if(index+1<n && ((s[index]=='1' && s[index+1]<='9') || (s[index]=='2' && s[index+1]<='6'))){
            ways += decode(s, index+2, n);
        }

        return dp[index] = ways;
    }

    int numDecodings(string s) {

        int n = s.size();

        memset(dp, -1, sizeof(dp));

        return decode(s, 0, n);
    }
};
