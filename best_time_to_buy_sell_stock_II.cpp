#include<iostream>
#include<vector>
#include<cstring>
using namespace std;



// Intuitive Solution

class Solution {

    public:

    int maxProfit(vector<int> &prices) {
        
        int i=0, profit=0;
        int buy, sell;

        while(i < prices.size()-1) {

            while(i<prices.size()-1 && prices[i+1] <= prices[i]) {
                i++;
            }
            buy = prices[i];

            while(i<prices.size()-1 && prices[i+1] > prices[i]) {
                i++;
            }
            sell = prices[i];

            profit += sell - buy;
        }

        return profit;
    }
};




// Using Dynamic Programming

class Solution {

    public:

    int dp[30002][2];

    int earnMaxProfit(vector<int> &prices, int i, bool buy) {

        if(i>=prices.size()) {
            return 0;
        }

        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int opt1 = 0;
        int opt2 = 0;

        if(buy) {
            opt1 = -1*prices[i] + earnMaxProfit(prices, i+1, false);
        }
        else {
            opt1 = prices[i] + earnMaxProfit(prices, i+1, true);
        }

        opt2 = earnMaxProfit(prices, i+1, buy);

        return dp[i][buy] = max(opt1, opt2);
    }

    int maxProfit(vector<int> &prices) {

        memset(dp, -1, sizeof(dp));

        return earnMaxProfit(prices, 0, true);
    }
};