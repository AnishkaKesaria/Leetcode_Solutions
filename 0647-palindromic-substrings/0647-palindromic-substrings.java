class Solution {

    private int findPalindrome(String s, int left, int right, int len) {
        int count = 0;
        while(left>=0 && right<len) {
            if(s.charAt(left)==s.charAt(right)) {
                count++;
                left--;
                right++;
            }
            else
                return count;
        } 

        return count;
    }

    public int countSubstrings(String s) {
        int count = 0;
        int n = s.length();
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            //find oddLenPalindrome
            int oddLenPalindrome = findPalindrome(s, i, i, n);
            //find even length plaindrome
            int evenLenPalindrome = findPalindrome(s, i, i+1, n);
            count += (oddLenPalindrome + evenLenPalindrome);
        }

        return count;
    }
}