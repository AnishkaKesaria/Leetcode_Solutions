class Solution {
    public String convert(String s, int numRows) {
        if(numRows>=s.length() || numRows==1)
            return s;


        String ans = "";
        int diff = (numRows-1)*2;
        for(int i=0; i<numRows; i++) {
            ans += s.charAt(i);
            int j = i + (diff - 2*i);
            int k = i+diff;
            while(k<s.length() || j<s.length()) {
            if(i!=0 && i!=(numRows-1)) {
                ans += s.charAt(j);
            }
            if(k<s.length()) {
                ans += s.charAt(k);
            }
            k += diff;
            j += diff;
            }
        }

        return ans;
    }
}