class Solution {
    int findMaxLoot(int index, int[] nums, int[] dp) {
        if(index>=nums.length)
            return 0;
        
        if(dp[index]!=Integer.MIN_VALUE)
            return dp[index];
        
        //loot
        int loot = findMaxLoot(index+2, nums, dp) + nums[index];
        //no loot
        int noLoot = findMaxLoot(index+1, nums, dp);

        dp[index] = Math.max(loot, noLoot);
        return dp[index];
    }

    public int rob(int[] nums) {
        int index = 0;
        int[] dp = new int[nums.length+1];
        Arrays.fill(dp, Integer.MIN_VALUE);
        int ans = findMaxLoot(index, nums, dp);
        return ans;
    }
}