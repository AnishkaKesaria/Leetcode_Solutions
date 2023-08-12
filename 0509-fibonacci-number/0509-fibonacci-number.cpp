class Solution {
public:
    
    int findfib(vector<int> &dp, int n)
    {
        if(n==1 || n==0)
            return n;
        if(dp[n]==-1)
            dp[n] = findfib(dp, n-1) + findfib(dp, n-2);
        return dp[n];
    }
    
    int fib(int n) {
        //Step 1
        vector<int> dp(n+1, -1);
        return findfib(dp, n);
    }
};