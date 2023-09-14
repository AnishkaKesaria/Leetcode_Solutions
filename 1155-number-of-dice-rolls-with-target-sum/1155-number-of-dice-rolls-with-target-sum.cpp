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

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp (n+1, vector<int> (target+1, -1));
        return numRollsMem(n,k,target,dp);
    }
};