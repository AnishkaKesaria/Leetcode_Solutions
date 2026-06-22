class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int currSum = 0;
        for(int i=0; i<costs.length; i++) {
            currSum += costs[i];
            if(currSum>coins)
                return i;
        }

        return costs.length;
    }
}