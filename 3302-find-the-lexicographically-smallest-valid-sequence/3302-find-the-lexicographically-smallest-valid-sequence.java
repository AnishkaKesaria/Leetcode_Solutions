class Solution {
    public int[] validSequence(String word1, String word2) {
        int match = 0;
        int[] rightMatch = new int[word1.length()];
        int n1 = word1.length() -1;
        int n2 = word2.length() -1;
        for(int i=n1; i>=0; i--) {
            if(n2<0) {
                rightMatch[i] = rightMatch[i+1];
                continue;
            }
            if(word1.charAt(i)==word2.charAt(n2)) {
                match++;
                n2--;
            }

            rightMatch[i] = match;
        }

        n2 = word2.length() -1;
        int[] ans = new int[word2.length()];
        // if(rightMatch[0]<n2) {
        //     System.out.println(rightMatch[0]);
        //     return new int[0];
        // }
        
        int j = 0;
        boolean isChangePossible = true;
        for(int i=0; i<=n1; i++) {
            if(word1.charAt(i)==word2.charAt(j)) {
                ans[j] = i;
                j++;
            } else {
                if(isChangePossible && i+1<rightMatch.length && j+rightMatch[i+1]+1>=word2.length()) {
                    isChangePossible = false;
                    ans[j] = i;
                    j++;
                }
            }

            if(j==word2.length())
                return ans;
        }
        if(j==word2.length())
            return ans;
        else
            return new int[0];
    }
}