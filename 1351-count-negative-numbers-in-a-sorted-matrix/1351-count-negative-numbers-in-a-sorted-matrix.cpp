class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negCount = 0;
        for(int i= grid.size()-1; i>=0; i--) {
            for(int j = grid[i].size()-1; j>=0; j--) {
                if(grid[i][j]<0)
                    negCount++;
                else
                    j=-1;
            }
        }
        return negCount;
    }
};