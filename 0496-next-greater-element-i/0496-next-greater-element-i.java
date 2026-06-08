class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] ans = new int[n];
        Arrays.fill(ans,-1);
        for(int i=0; i<nums1.length; i++) {
            boolean found = false;
            for(int j=0; j<nums2.length; j++) {
                if(found || nums1[i]==nums2[j]) {
                    if(nums2[j]>nums1[i]) {
                        ans[i] = nums2[j];
                        break;
                    } else if (nums2[j]==nums1[i]) {
                        found = true;
                    }
                }
            }
        }
        return ans;
    }
}