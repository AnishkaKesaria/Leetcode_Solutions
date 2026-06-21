class Solution {
    public int maxBuilding(int n, int[][] restrictions) {
        // restrictions.add(new int[]{1, 0});
        Arrays.sort(restrictions,(a,b) -> Integer.compare(a[0], b[0]));

        // updating currHeight;
        for(int i=0; i<restrictions.length; i++) {
            if(i==0)
            {
                int maxHeight = restrictions[i][0] - 1;
                int restrictedHeight = restrictions[i][1];
                int currHeight = Math.min(restrictedHeight, maxHeight);
                restrictions[i][1] = currHeight;
                continue;
            }
            else {
                int distance = restrictions[i][0] - restrictions[i-1][0];
                int maxHeight = distance + restrictions[i-1][1];
                int restrictedHeight = restrictions[i][1];
                int currHeight = Math.min(restrictedHeight, maxHeight);
                restrictions[i][1] = currHeight;
            }
        }

        // updating currHeight;
        for(int i=restrictions.length-2; i>=0 && i<restrictions.length-1; i--) {
                int distance = restrictions[i+1][0] - restrictions[i][0];
                int maxHeight = distance + restrictions[i+1][1];
                int restrictedHeight = restrictions[i][1];
                int currHeight = Math.min(restrictedHeight, maxHeight);
                restrictions[i][1] = currHeight;
        }

        // calculating maxHeight;
        int maxHeight = 0;
        int lastIndex = 1;
        int lastHeight = 0;
        for(int i=0; i<restrictions.length; i++) {

            if(i==0) {
                int leftHeight = 0;
                int rightHeight = restrictions[i][1];
                if(leftHeight==rightHeight) {
                    int dist = restrictions[i][0] - 1;
                    int currMax = dist/2;
                    maxHeight = Math.max(maxHeight, currMax);
                } else {
                    int dist = restrictions[i][0] - 1;
                    dist -= Math.abs(leftHeight-rightHeight);
                    int heightDiff = restrictions[i][1];
                    int currMax = dist/2 + Math.max(leftHeight,rightHeight);
                    maxHeight = Math.max(maxHeight, currMax);
                }
            } else {

            int leftHeight = restrictions[i-1][1];
            int rightHeight = restrictions[i][1];
            if(leftHeight==rightHeight) {
                int dist = restrictions[i][0] - restrictions[i-1][0];
                int currMax = dist/2 + leftHeight;
                maxHeight = Math.max(maxHeight, currMax);
            } else {
                int dist = restrictions[i][0] - restrictions[i-1][0];
                dist -= Math.abs(leftHeight-rightHeight);
                int heightDiff = restrictions[i][1] - restrictions[i-1][1];
                int currMax = dist/2 + Math.max(leftHeight,rightHeight);
                maxHeight = Math.max(maxHeight, currMax);
            }
            }
            lastIndex = restrictions[i][0];
            lastHeight = restrictions[i][1];

        }

        if(lastIndex<n) {
            int currHeight = lastHeight + (n-lastIndex);
            maxHeight = Math.max(maxHeight, currHeight);
        }

        return maxHeight;
    }
}