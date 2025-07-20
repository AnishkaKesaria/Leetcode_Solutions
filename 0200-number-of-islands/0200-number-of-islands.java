class Solution {
    private void bfs(char[][] grid, boolean visited[][], int i, int j) {
        visited[i][j] = true;
        Queue<Pair<Integer,Integer>> q = new LinkedList<Pair<Integer,Integer>>();
        q.add(new Pair(i,j));

        int r = grid.length;
        int c = grid[0].length;

        int[] dRow = {-1, 1, 0, 0};
        int[] dCol = {0, 0, -1, 1};

        while(!q.isEmpty()) {
            int row = q.peek().getKey();
            int col = q.peek().getValue();
            System.out.println(row + " "+ col);
            q.remove();

            for(int d = 0; d<4; d++) {
                    int currRow = row+dRow[d];
                    int currCol = col+dCol[d];
                    if(currRow>=0 && currRow<r && currCol>=0 && currCol<c && grid[currRow][currCol]=='1' && !visited[currRow][currCol]) {
                        System.out.println("adding in queue");
                        visited[currRow][currCol] = true;
                        q.add(new Pair(currRow, currCol));
                    }
            }
        }

        return;
    }

    private void dfs(char[][] grid, boolean visited[][], int i, int j) {
        if(i<0 || i>=grid.length || j<0 || j>=grid[i].length || grid[i][j]!='1' || visited[i][j]==true)
            return;

        visited[i][j] = true;
            dfs(grid, visited,i+1,j);
            dfs(grid, visited,i-1,j);
            dfs(grid, visited,i,j+1);
            dfs(grid, visited,i,j-1);
        return;
    }

    public int numIslands(char[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        boolean visited[][] = new boolean[r][c];
        int count = 0;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    count++;
                    dfs(grid, visited,i,j);
                }
            }
        }

        return count;
    }
}