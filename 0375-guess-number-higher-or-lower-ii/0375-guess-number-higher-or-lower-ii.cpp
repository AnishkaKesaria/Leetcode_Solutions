class Solution {
public:
    int solveUsingRec(int start, int end)
    {
        if(start>=end)
            return 0;

        int ans = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i + max(solveUsingRec(start, i-1), solveUsingRec(i+1, end)));
        }

        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int>> &dp)
    {
        if(start>=end)
            return 0;

        if(dp[start][end]!=INT_MIN)
            return dp[start][end];

        int ans = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i + max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)));
            // ans = min(ans, i+max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1,end,dp)));
        }

        dp[start][end] = ans;
        return dp[start][end];
    }

    // int solveUsingTab(int n)
    // {
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    //     for(int start = 1; start<=n; start++)
    //     {
    //         for(int end = n; end>=1; end--)
    //         {
    //             int ans = INT_MAX;

    //             for(int i=start; i<=end; i++)
    //             {
    //                 ans = min(ans, i+ max(dp[start][i-1], dp[i+1][end]));
    //             }

    //             dp[start][end] = ans;
    //         }
    //     }

    //     return dp[n][1];
    // }

    int solveUsingTab(int n)
    {
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

        // for(int start=1; start<=n; start++)
        // {
        //     for(int end=n; end>=1; end--)
        //     {
        //         if(start<end)
        //         {
        //             int ans = INT_MAX;

        //             for(int i=start; i<=end; i++)
        //             {
        //                 if(i-1>=1 && i+1<=n)
        //                     ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
        //             }

        //             dp[start][end] = ans;
        //         }
        //     }
        // }

        for(int start = n; start>=1; start--)
        {
            for(int end = 1; end<=n; end++)
            {
                if(start<end)
                {
                    int ans = INT_MAX;

                    for(int i=start; i<=end; i++)
                    {
                        if(i-1>=1 && i+1<=n)
                            ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                    }

                    dp[start][end] = ans;

                    if(ans==INT_MAX)
                        dp[start][end] = 1;
                }
                else
                    dp[start][end] = 0;
            }
        }

        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        // int ans = solveUsingRec(start, end);
        // vector<vector<int>> dp (n+1, vector<int> (n+1, INT_MIN));
        // int ans = solveUsingMem(start, end, dp);
        int ans = solveUsingTab(n);
        return ans;
    }
};