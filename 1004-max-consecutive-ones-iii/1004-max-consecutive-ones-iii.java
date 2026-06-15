class Solution {
    public int longestOnes(int[] nums, int k) {
        int flip = 0;
        int ans = 0;
        int i=0;
        int j = 0;
        while(j<nums.length){
            if(nums[j]==0)
                flip++;
            j++;
            if(flip>k) {
                ans = Math.max(ans, j-i-1);
                while(flip>k) {
                    if(nums[i]==0) {
                        flip--;
                    } 
                    i++;
                }
            }
        }
        
        ans = Math.max(ans, j-i);
        return ans;
    }
}