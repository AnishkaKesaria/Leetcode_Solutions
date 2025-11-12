class Solution {
    public String longestPalindrome(String s) {
        String ans = "";
        int maxLen = 0;

        for(int i=0; i<s.length(); i++) {
            //odd length
            int l = i, r = i;
            while(l>=0 && r<s.length() && l<=r && s.charAt(l)==s.charAt(r)) {
                int currLen = r-l+1;
                if(currLen>=maxLen) {
                    ans = s.substring(l, r+1);
                    maxLen = currLen;
                }
                l--;
                r++;
            }
        
            //even length
            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && l<=r && s.charAt(l)==s.charAt(r)) {
                int currLen = r-l+1;
                if(currLen>=maxLen) {
                    ans = s.substring(l, r+1);
                    maxLen = currLen;
                }
                l--;
                r++;
            } 
        }

        return ans;
    }
}