class Solution {
    int MOD = 1000000007;
public:
    int numRollsMem(int n, int k, int target, vector<vector<int>> &dp)
    {
        if(target==0 && n==0)
            return 1;
        if(target==0 && n!=0)
            return 0;
        if(target<0)
            return 0;
        if(n==0)
            return 0;

        if(dp[n][target]!= -1)
            return dp[n][target];

        long long int ans = 0;
        for(int i=1; i<=k; i++)
        {
            ans += numRollsMem(n-1, k, target-i, dp);
        }
        dp[n][target] = ans%MOD;
        return dp[n][target];
    }

    int numRollsTab(int n, int k, int target)
    {
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        dp[0][0] = 1;

        for(int index=1; index<=n; index++)
        {
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {
                    if(t-i>=0)
                        ans += dp[index-1][t-i];
                }
                dp[index][t] = ans%MOD;
            }
        }

        return dp[n][target];
    }
    
    int numRollsTabSO(int n, int k, int target)
    {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        
        prev[0]=1;
        
        for(int index=1; index<=n; index++)
        {
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {
                    if(t-i>=0)
                        ans += prev[t-i];
                }
                curr[t] = ans%MOD;
            }
            prev = curr;
        }

        return curr[target];
        
        return curr[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp (n+1, vector<int> (target+1, -1));
        // return numRollsMem(n,k,target,dp);
        // vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        // dp[0][0] = 1;

        // for(int index=1; index<=n; index++)
        // {
        //     for(int t=1; t<=target; k++)
        //     {
        //         long long int ans = 0;
        //         for(int i=1; i<=k; i++)
        //         {
        //             if(t-i>=0)
        //                 ans += dp[index-1][t-i];
        //         }
        //         dp[index][t] = ans%MOD;
        //     }
        // }

        // return dp[n][target];
        return numRollsTabSO(n,k,target);
    }
};