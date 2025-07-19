class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean visited[] = new boolean[n];
        int count = 0;

        for(int i=0; i<n; i++) {
            if(visited[i]!=true) {
                count++;
                dfs(i, isConnected, visited);
            }
        }

        return count;
    }

    private void dfs(int i, int[][] isConnected, boolean visited[]) {
        visited[i] = true;

        for(int j= 0; j<isConnected.length; j++) {
            if(isConnected[i][j]==1) {
                if(visited[j] !=true) {
                    dfs(j, isConnected, visited);
                }
            }
        }

        return;
    }
}