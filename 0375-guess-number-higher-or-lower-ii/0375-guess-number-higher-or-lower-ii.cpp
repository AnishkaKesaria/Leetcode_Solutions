class Solution {
public:
    int solTab(int n)
    {
        vector<vector<int>> dp (n+2, vector<int>(n+1, 0));

        for(int start=n; start>=1; start--)
        {
            for(int end = 1; end<=n; end++)
            {

                if(start>=end)
                    continue;

                int ans = INT_MAX;
                for(int i=start; i<=end; i++)
                {
                    ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }

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
        // vector<vector<int>> dp (n+1, vector<int>(n+1, INT_MAX));
        // int ans = solRec(1, n, dp);
        int ans = solTab(n);
        return ans;
    }
};