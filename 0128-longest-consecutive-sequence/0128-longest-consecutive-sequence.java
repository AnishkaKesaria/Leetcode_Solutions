class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new TreeSet<>();
        int prev = 0;
        for(int i:nums) {
            s.add(i);
            if(i<prev)
                prev = i;
        }

        int currMax = 0;
        int count = 0;
        for(int i:s) {
            if(i==prev || i==prev+1) {
                count++;
            } else {
                if(count>currMax)
                    currMax = count;
                count = 1;
            }
            prev = i;
        }

        return Math.max(currMax,count);
    }
}