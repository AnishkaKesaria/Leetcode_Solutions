class Solution {
public:
    int findMaxProfit(vector<int>& prices, int index, bool hold, vector<vector<int>> &dp) {
        if(index==prices.size())
            return 0;

        if(dp[index][hold] != -1)
            return dp[index][hold];
            
        int profit = 0;

        if(!hold) {
            //buy
            int buy = -prices[index] + findMaxProfit(prices, index+1, true, dp);
            //nobuy
            int skip = findMaxProfit(prices, index+1, false, dp);
            profit = max(buy, skip);
        } else {
            //sell
            int sell = prices[index] + findMaxProfit(prices, index+1, false, dp);
            //nosell
            int skip = findMaxProfit(prices, index+1, true, dp);;
            profit = max(sell, skip);
        }

        dp[index][hold] = profit;
        return dp[index][hold];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp( n, vector<int> (2,-1));
        return findMaxProfit(prices, 0, false, dp);
    }
};