class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int targetSum = (n*n)*((n*n)+1)/2;
        int currSum = 0;
        HashMap<Integer, Integer> m = new HashMap<>();
        int[] ans = new int[2];
        for(int[] i:grid) {
            for(int j:i) {
                if(m.containsKey(j)) {
                    ans[0] = j;
                } else {
                    m.put(j,1);
                    currSum += j;
                }
            }
        }

        ans[1] = targetSum - currSum;
        return ans;
    }
}