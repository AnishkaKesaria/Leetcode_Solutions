class Solution {
public:
    int LIS(vector<int>& nums, int start, int prevMax)
    {
        if(start>=nums.size()-1)
            return 1;

        //include
        int inc = 0;
        if(prevMax<nums[start+1])
            inc = 1 + LIS(nums, start+1, nums[start+1]);

        //exclude
        int exc = LIS(nums, start+1, prevMax);

        return max(inc, exc);

    }

    int LISMem(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=nums.size()-1)
            return 1;

        if(dp[i][j]!= -1)
            return dp[i][j];

        int inc = 0;
        if(nums[j]<nums[i+1])
            inc = 1+LISMem(nums, i+1, i+1, dp);
        
        int exc = LISMem(nums, i+1, j, dp);

        dp[i][j] = max(inc, exc);
        return dp[i][j];
    }


    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;

        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), -1));

        // for(int i=0; i<nums.size(); i++)
        // {
        //     ans = max(ans, LIS(nums, i, nums[i]));
        // }

        for(int i=0; i<nums.size(); i++)
        {
            ans = max(ans, LISMem(nums, i, i, dp));
        }
        return ans;
    }
};