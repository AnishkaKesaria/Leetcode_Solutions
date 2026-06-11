class Solution {
    public int lengthOfLastWord(String s) {
        int prevLength = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)==' ') 
                continue;
            else if(i>0 && s.charAt(i)!=' ' && s.charAt(i-1)==' ')
                prevLength = 1;
            else 
                prevLength++;
        }

        return prevLength;
    }
}