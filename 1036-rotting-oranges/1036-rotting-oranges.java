class Node {
    int row;
    int col;
    int time;

    Node(int a, int b, int c) {
        this.row = a;
        this.col = b;
        this.time = c;
    }
}

class Solution {

    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean visited[][] = new boolean[n][m];
        Queue<Node> q = new LinkedList<Node>(); 
        int fresh = 0;
        int maxt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2 && !visited[i][j]) {
                    q.add(new Node(i, j, 0));
                    visited[i][j] = true;
                } else if (grid[i][j]==1)
                    fresh++;
            }
        }

        int dRow[] = {0,0,-1,1};
        int dCol[] = {1,-1,0,0};
        int count = 0;

        while(!q.isEmpty()) {
            Node top = q.poll();
            System.out.println(top.row + " " + top.col + " "+top.time);
            int row = top.row;
            int col = top.col;
            int t = top.time;
            maxt = Math.max(maxt, t);

            for(int d = 0; d<4; d++){
                int currRow = row+dRow[d];
                int currCol = col+dCol[d];
                System.out.println("Printing: " + currRow+ " "+ currCol);

                if(currRow>=0 && currRow<n && currCol>=0 && currCol<m && grid[currRow][currCol]==1 && !visited[currRow][currCol]) {
                    grid[currRow][currCol]=2;
                    q.add(new Node(currRow, currCol, t+1));
                    visited[currRow][currCol] = true;
                    count++;
                }
            }
        }

        if(count==fresh)
            return maxt;
        else
            return -1;
    }
}