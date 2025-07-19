class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        Integer[] dp = new Integer[n+2];
        return decodings(s,0, dp);
    }

    private int decodings(String s, int i, Integer[] dp) {
        if(i>=s.length())
            return 1;
        
        else if(s.charAt(i)=='0')
            return 0;
        else if(i==s.length()-1)
            return 1;

        else if(dp[i]!=null)
            return dp[i];

        else if(Integer.parseInt(s.substring(i, i+2))<=26)
            return (dp[i] = (decodings(s,i+1,dp)+decodings(s,i+2,dp)));
    
        return (dp[i]=decodings(s,i+1,dp));
    }
}