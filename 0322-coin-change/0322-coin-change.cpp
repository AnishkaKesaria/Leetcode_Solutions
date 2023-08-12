class Solution {
public:
    int solution(vector<int>& coins, int amount, vector<int> &dp) {
        if(amount==0)
            return 0;
        if(amount<0)
            return INT_MAX;
        if(dp[amount]!=-1)
            return dp[amount];

        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++)
        {
            int tempAns = solution(coins, amount-coins[i], dp);
            if(tempAns!=INT_MAX)
                ans = min(ans, tempAns+1);
        }

        dp[amount] = ans;
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        //Step 1
        vector<int> dp(amount+1, -1);
        int ans = solution(coins, amount, dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};

