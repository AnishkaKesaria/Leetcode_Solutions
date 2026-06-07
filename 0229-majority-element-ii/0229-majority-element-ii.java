class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        int cutoff = n/3;

        HashMap<Integer, Integer> m = new HashMap<>();
        for(int i=0; i<nums.length; i++) {
            m.put(nums[i], m.getOrDefault(nums[i],0) + 1);

            if(m.get(nums[i])>cutoff) {
                ans.add(nums[i]);
                m.put(nums[i], Integer.MIN_VALUE);
            }

        }

        return ans;
    }
}