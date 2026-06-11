class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int n = s.length();
        int len = 0;
        while(n>0) {
            if(s.charAt(--n)==' ')
                return len;
            else
                len++;
        }

        return len;
    }
}