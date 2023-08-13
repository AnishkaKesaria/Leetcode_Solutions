class Solution {
public:
    // int solveUsingRec(vector<int> &nums, int n)
    // {
    //     if(n<0)
    //         return 0;
    //     if(n==0)
    //         return nums[0];

    //     int include = solveUsingRec(nums, n-2) + nums[n];
    //     int exclude = solveUsingRec(nums, n-1);

    //     return max(include,exclude);
    // }

    int solveUsingMem(vector<int> &nums, int n, vector<int>&dp)
    {
        if(n<0)
            return 0;
        if(n==0)
            return nums[0];

        if(dp[n]!=-1)
            return dp[n];

        int include = solveUsingMem(nums, n-2, dp) + nums[n];
        int exclude = solveUsingMem(nums, n-1, dp);

        dp[n] = max(include, exclude);
        return dp[n];
    }
    
    int solveUsingTab(vector<int>&nums, int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        
        for(int i=1; i<=n; i++)
        {
            int temp = 0;
            if(i-2>=0)
                temp = dp[i-2];
            int include = temp + nums[i];
            int exclude = dp[i-1];
            
            dp[i] = max(include, exclude);
        }
        return dp[n];
    }
    
    int solveUsingSpaceOpt(vector<int> &nums, int n)
    {
        if(n==0)
            return nums[0];
        
        int prev2 = 0;
        int prev1 = nums[0];
        
        int curr = 0;
        
        for(int i=1; i<=n; i++)
        {
            int temp = 0;
            if(i-2>=0)
                temp = prev2;
            int include = temp + nums[i];
            int exclude = prev1;
            
            curr = max(include, exclude);
            
            prev2 = prev1;
            prev1 = curr;
            
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        // vector<int> dp(n+1, -1); 
        int ans = solveUsingSpaceOpt(nums,n);
        return ans;
    }
};