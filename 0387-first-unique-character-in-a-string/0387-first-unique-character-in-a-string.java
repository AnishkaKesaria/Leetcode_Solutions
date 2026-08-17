class Solution {
    public int firstUniqChar(String s) {
        int[] charCount = new int[26];
        Arrays.fill(charCount, 0);
        for(char ch: s.toCharArray()) {
            charCount[ch-'a'] += 1;;
        }

        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if(charCount[ch-'a']==1)
                return i;
        }

        return -1;
    }
}