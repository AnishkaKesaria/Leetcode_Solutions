class Solution {
    public int compress(char[] chars) {
        if(chars.length==1)
            return 1;

        int count = 1;
        char prev = chars[0];
        String s = "";
        int n = chars.length;
        for(int i=1; i<n; i++) {
            if(chars[i]==prev)
                count++;
            else {
                s += prev;
                if(count>1)
                    s += String.valueOf(count);
                count = 1;
                prev = chars[i];
            }
        }

        s += prev;
        if(count>1)
            s += String.valueOf(count);

        int res = s.length();
        //char[] ans = new char[res];
        for(int i=0; i<res; i++) {
            chars[i] = s.charAt(i);
        }

        return res;
    }
}