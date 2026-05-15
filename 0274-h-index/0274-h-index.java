class Solution {
    boolean isPossible(int target, int[] citations) {
        int count=0;
        for(int i=0; i<citations.length; i++) {
            if(citations[i]>=target)
                count++;
            if(count>=target)
                return true;
        }

        return false;
    }

    public int hIndex(int[] citations) {
        int minH = 0;
        int maxH = citations.length;
        int ans = minH;

        while(minH<=maxH) {
            int target = minH + (maxH-minH)/2;
            if(isPossible(target, citations)){
                ans = Math.max(target, ans);
                minH = target+1;
            } else {
                maxH = target - 1;
            }
        }


        return ans;
    }
}