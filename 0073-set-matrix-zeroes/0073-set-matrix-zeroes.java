class Solution {
    public void setZeroes(int[][] matrix) {
        ArrayList<Integer> row = new ArrayList<>();
        ArrayList<Integer> col = new ArrayList<>();

        for(int i=0; i<matrix.length; i++) {
            for(int j=0; j<matrix[i].length; j++) {
                if(matrix[i][j] == 0) {
                    row.add(i);
                    col.add(j);
                }
            }
        }

        for(int i=0; i<row.size(); i++) {
            int r = row.get(i);
            int c = col.get(i);
            for(int j=0; j<matrix[0].length; j++) {
                matrix[r][j] = 0;
            }
            for(int j=0; j<matrix.length; j++) {
                matrix[j][c] = 0;
            }
        }

        return;
    }
}