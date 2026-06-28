class Solution {
    public int candy(int[] ratings) {

        int len = ratings.length;
        int[] candies = new int[len];
        int candyCount = len;
        Arrays.fill(candies, 1);
        for(int i=0; i<len; i++) {
            if(i==0 && i+1<len) {
                if(ratings[i]>ratings[i+1]) {
                    candies[i] += 1;
                    candyCount++;
                }
            } else if (i==len-1 && i-1>=0) {
                if(ratings[i]>ratings[i-1]) {
                    int diff = candies[i-1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                }
            } else {
                if(i-1>=0 && i+1<len && ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]) {
                    int diff = Math.max(candies[i-1], candies[i+1]) - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                } else if(i-1>=0 && ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]) {
                    int diff = candies[i-1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                } else if(i+1<len && ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) {
                    int diff = candies[i+1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                }
            }
        }

        for(int i=len-1; i>=0; i--) {
            if(i==len-1 && i-1>=0) {
                if(ratings[i]>ratings[i-1] && candies[i-1]>=candies[i]) {
                    int diff = candies[i-1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                }
            } else if(i==0 && i+1<len) {
                if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) {
                    int diff = candies[i+1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                }
            } else {
                if(i-1>=0 && i+1<len && (ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]) &&  candies[i]<=Math.max(candies[i-1], candies[i+1])) {
                    int diff = Math.max(candies[i-1], candies[i+1]) - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                } else if(i-1>=0 && ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]) {
                    int diff = candies[i-1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                } else if(i+1<len && ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) {
                    int diff = candies[i+1] - candies[i];
                    candies[i] += (diff+1);
                    candyCount += (diff+1);
                }
            }
        }


        return candyCount;
    }
}