class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        Arrays.sort(nums);
        int maxVal = nums[nums.length - 1];
        int j=0;
        List<Integer> ans = new ArrayList<>();
        for(int i=nums[0]; i<=maxVal ; i++) {
            if(i!=nums[j]) {
                ans.add(i);
            } else {
                j++;
            }
        }
        return ans;
    }
}