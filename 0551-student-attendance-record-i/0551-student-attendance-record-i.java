class Solution {
    public boolean checkRecord(String s) {
        int absent = 0;
        int late = 0;
        boolean prevLate = false;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)=='A') {
                absent++;
                if(absent>=2)
                    return false;
            }
            if(s.charAt(i)=='L') {
                if(prevLate==true && late==2)
                    return false;
                else {
                    prevLate = true;
                    late++;
                }
            }
            else {
                prevLate = false;
                late = 0;
            }
        }

        return true;
    }
}