class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int total = 0;
        for(int i: nums) {
            total += i;
        }

        int target = n*(n+1)/2;
        return (target-total);
    }
}