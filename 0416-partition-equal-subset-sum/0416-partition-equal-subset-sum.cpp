class Solution {
public:
    bool isSubsetSum(vector<int> &nums, int target, int currIndex)
    {
        cout<<target<<endl;
        if(currIndex>=nums.size())
            return false;
        if(target==0)
            return true;
        if(target<0)
            return false;

        //include
        bool include = isSubsetSum(nums, target-nums[currIndex], currIndex + 1);

        //exclude
        bool exclude = isSubsetSum(nums, target, currIndex + 1);

        return (include||exclude);
    }

    bool isSubsetSumDP(vector<int> &nums, int target, int currIndex, vector<vector<int>> &dp)
    {
        if(currIndex>=nums.size())
            return false;
        if(target==0)
            return true;
        if(target<0)
            return false;

        if(dp[target][currIndex]!=-1)
            return dp[target][currIndex];

        bool include = isSubsetSumDP(nums, target-nums[currIndex], currIndex+1, dp);
        bool exclude = isSubsetSumDP(nums, target, currIndex+1, dp);

        dp[target][currIndex] = include||exclude;
        return dp[target][currIndex];
    }

    bool isSubsetSumMem(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size()+1, vector<int> (target+1, 0));
        for(int i=0; i<nums.size(); i++)
        {
            dp[i][0] = 1;
        }

        for(int index = nums.size()-1; index>=0; index--)
        {
            for(int currTarget = 1; currTarget<=target; currTarget++)
            {
                bool include = 0;
                if(currTarget-nums[index]>=0)
                    include = dp[index+1][currTarget-nums[index]];
                bool exclude = dp[index+1][currTarget];

                dp[index][currTarget] = include||exclude;
            }
        }

        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        int target = sum/2;
        int currIndex = 0;
        // vector<vector<int>> dp(target+1, vector<int> (nums.size(), -1));
        return isSubsetSumMem(nums, target);
    }
};