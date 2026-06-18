class Solution {
    private boolean isPossible(int[] nums, int index, Pair<Boolean, Boolean>[] dp) {
        if(dp[index].getKey()==true)
            return dp[index].getValue();

        if(index==nums.length-1)
            return true;
        else if (index>nums.length-1)
            return false;
        else if (nums[index]==0)
            return false;
        else {
            int maxJump = nums[index];
            boolean ans = false;
            int currJump = 1;
            while(currJump<=maxJump) {
                ans = (ans || isPossible(nums, index+currJump, dp));
                currJump++;
            }
            dp[index] = new Pair<> (true, ans);
            return dp[index].getValue();
        }
    }

    public boolean canJump(int[] nums) {
        int currIndex = 0;
        Pair<Boolean, Boolean> dp[] = new Pair[nums.length+1];

        for(int i=0; i<nums.length; i++) {
            dp[i] = new Pair<> (false, false);
        }

        boolean ans = isPossible(nums, currIndex, dp);
        return ans;
    }
}