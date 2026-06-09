class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int currMax = Integer.MIN_VALUE;
        int currMin = Integer.MAX_VALUE;
        for(int i: nums) {
            currMax = (i>currMax) ? i : currMax;
            currMin = (i<currMin) ? i : currMin;
        }

        return ((long)k*(currMax-currMin));
    }
}