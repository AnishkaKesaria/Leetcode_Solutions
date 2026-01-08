class Solution {
public:

    int findMaxProfit(vector<int>& prices, int index, int hold, int cap, vector<vector<vector<int>>> &dp) {
        if(cap==0)
            return 0;
        if(index==prices.size())
            return 0;
        
        if(dp[index][hold][cap]!=-1)
            return dp[index][hold][cap];

        int profit = 0;

        if(hold==0)
        {
            //buy
            int buy = -prices[index] + findMaxProfit(prices, index+1, 1, cap, dp);
            //skip
            int skip = findMaxProfit(prices, index+1, 0, cap, dp);
            profit = max(buy,skip);
        } else {
            //sell
            int sell = prices[index] + findMaxProfit(prices, index+1, 0, cap-1, dp);
            //skip
            int skip = findMaxProfit(prices, index+1, 1, cap, dp);
            profit = max(sell,skip);
        }

        dp[index][hold][cap] = profit;
        return dp[index][hold][cap];
    }

    int maxProfit(vector<int>& prices) {
        int cap = 2;
        int n = prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));
        return findMaxProfit(prices, 0, 0, cap, dp);
    }
};