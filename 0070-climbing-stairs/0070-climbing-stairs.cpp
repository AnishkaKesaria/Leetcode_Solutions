class Solution {
public:
    // int climbStairs(int n) {
    //     if(n==0 || n==1)
    //         return 1;
        
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }

    int climbStairsDP(int n, vector<int> &dp)
    {
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];

        int ans =  climbStairsDP(n-1,dp) + climbStairsDP(n-2,dp);
        dp[n] = ans;

        return dp[n];
    }
    
    
    int climbStairsTab(int n)
    {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
    

    int climbStairs(int n)
    {
        // vector<int> dp(n+1, -1);
        int ans = climbStairsTab(n);
        return ans;
    }
};