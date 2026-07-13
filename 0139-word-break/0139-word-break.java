class Solution {
    private int isPresent(String s, List<String> wordDict, int startIndex, int possibleArray[]) {
        if(startIndex>=s.length())
            return 1;
        
        if(possibleArray[startIndex]!=-1)
            return possibleArray[startIndex];

        boolean isPossible = false;

        for(int i=startIndex; i<s.length(); i++) {
            String subString = s.substring(startIndex, i+1);
            if(wordDict.contains(subString)) {
                if(isPresent(s, wordDict, i+1, possibleArray)==1){
                    isPossible=true;
                    possibleArray[startIndex] = 1;
                    return possibleArray[startIndex];
                }
            }
        }

        if(isPossible)
            possibleArray[startIndex] = 1;
        else
            possibleArray[startIndex] = 0;

        return possibleArray[startIndex];
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        int possibleArray[] = new int[n+1];
        Arrays.fill(possibleArray, -1);

        int ans = isPresent(s, wordDict, 0, possibleArray);
        if(ans==1)
            return true;
        else
            return false;
    }
}