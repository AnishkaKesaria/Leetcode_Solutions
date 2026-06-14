class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        int currSum = 0;
        int currMax = 0;
        for(int i=0; i<nums.length; i++) {
            if(nums[i]==0)
                currSum -= 1;
            else
                currSum++;
            
            if(currSum == 0)
                currMax = Math.max(currMax, i+1);
            else {
                if(m.containsKey(currSum)) {
                    int pos = m.get(currSum);
                    currMax = Math.max(currMax, i-pos);
                } else {
                    m.put(currSum, i);
                }
            }
        }

        return currMax;
    }
}