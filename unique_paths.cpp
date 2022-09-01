#include<iostream>
#include<vector>
using namespace std;


// Brute Force - we are going through certain blocks multiple times

class Solution {

    public:

    void helper(int m, int n, int i, int j, int &sum) {
        
        // Base case
        if(i==m-1 && j==n-1) {
            sum++;
            return;
        }

        // Recursive case
        if(i<m-1) {
            helper(m, n, i+1, j, sum);
        }
        if(j<n-1) {
            helper(m, n, i, j+1, sum);
        }
    }

    int uniquePaths(int m, int n) {

        int sum = 0;
        helper(m, n, 0, 0, sum);

        return sum;
    }
};


// Recursion Approach

class Solution {

    public:

    int paths(int m, int n, int i, int j) {
        
        // Base case
        if(i==m-1 && j==n-1) {
            return 1;
        }
        if(i>=m || j>=n) {
            return 0;
        }

        // Recursive case
        int ans = paths(m, n, i+1, j) + paths(m, n, i, j+1);
        
        return ans;

    }

    int uniquePaths(int m, int n) {
        
        int ans;
        ans = paths(m, n, 0 , 0);

        return ans;
    }
};


// Memoization

class Solution {

    public:

    int paths(int m, int n, int i, int j, vector<vector<int>> &dp) {
        
        // Base case
        if(i==m-1 && j==n-1) {
            return 1;
        }
        if(i>=m || j>=n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recursive case
        dp[i][j] = paths(m, n, i+1, j, dp) + paths(m, n, i, j+1, dp);
        
        return dp[i][j];

    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans;
        ans = paths(m, n, 0 , 0, dp);

        return ans;
    }
};


// Loop Approach

class Solution {

    public:

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n,1));

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};