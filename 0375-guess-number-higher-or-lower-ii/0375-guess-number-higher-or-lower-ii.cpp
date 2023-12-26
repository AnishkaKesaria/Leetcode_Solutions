class Solution {
public:
    int solRec(int start, int end, vector<vector<int>> &dp)
    {
        if(start>=end)
            return 0;

        if(dp[start][end] != INT_MAX)
            return dp[start][end];

        int ans = INT_MAX;
        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i + max(solRec(start, i-1, dp), solRec(i+1, end, dp)));
        }

        dp[start][end] = ans;
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp (n+1, vector<int>(n+1, INT_MAX));
        int ans = solRec(1, n, dp);
        return ans;
    }
};