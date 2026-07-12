class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] hash = new int[256];
        Arrays.fill(hash, -1);
        int maxLen = 0;
        int start = 0;
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if(hash[ch]!=-1) {
                start = Math.max(start, hash[ch] + 1);
            } 
            hash[ch] = i;
            maxLen = Math.max(maxLen, i-start+1);
        }

        return maxLen;
    }
}