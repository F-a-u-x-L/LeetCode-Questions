#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution {

    public:

    int helper(int n, int squareUpto) {

        // Base case 
        if(n<4) {
            return n;
        }

        int count = 0;

        count += n / (squareUpto*squareUpto);
        n = n % (squareUpto*squareUpto);
        if(n<4) {
            return count + n;
        }
        squareUpto = floor(sqrt(n));
        int ans = 10000;

        for(int i=squareUpto; i>1; i--) {
            int count = 0;  
            count = helper(n, i);
            ans = min(ans, count);
        }

        count += ans;

        return count;
    }

    int numSquares(int n) {

        int squareUpto = floor(sqrt(n));
        int ans = INT_MAX;

        for(int i=squareUpto; i>1; i--) {
            int count = 0;  
            count = helper(n, i);
            ans = min(ans, count);
        }

        ans = min(ans, n);

        return ans;
    }
};




class Solution {

    public:

    int helper(int n, int squareUpto, vector<int> &dp) {

        // Base case 
        if(n<4) {
            return n;
        }

        int count = 0;

        if(dp[n] > 0) {
            return dp[n];
        }

        count += n / (squareUpto*squareUpto);
        n = n % (squareUpto*squareUpto);
        if(n<4) {
            return count + n;
        }
        squareUpto = floor(sqrt(n));
        int ans = 10000;

        for(int i=squareUpto; i>1; i--) {
            int count = 0;  
            count = helper(n, i, dp);
            ans = min(ans, count);
        }

        count += ans;
        dp[n] = count;

        return count;
    }

    int numSquares(int n) {

        int squareUpto = floor(sqrt(n));
        int ans = INT_MAX;
        vector<int> dp(10001, -1);

        for(int i=squareUpto; i>1; i--) {
            int count = 0;  
            count = helper(n, i, dp);
            ans = min(ans, count);
        }

        ans = min(ans, n);
        dp[n] = ans;

        return ans;
    }
};




class Solution {

    public:

    int numSquares(int n) {

        vector<int> dp(n+1, INT_MAX);

        // Base case 
        dp[0] = 0;

        int count = 1;

        while(count*count <= n) {
            int sq = count*count;

            for(int i=sq; i<=n; i++) {
                dp[i] = min(dp[i-sq] + 1, dp[i]);
            }

            count++;
        }

        return dp[n];
    }
};