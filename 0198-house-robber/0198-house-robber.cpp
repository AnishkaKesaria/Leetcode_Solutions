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

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1, -1); 
        int ans = solveUsingMem(nums,n, dp);
        return ans;
    }
};