class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int leastrow = m;
        int leastcol = n;
        for(int i=0; i<ops.size(); i++)
        {
            leastrow = min(leastrow, ops[i][0]);
            leastcol = min(leastcol, ops[i][1]);
        }
        return (leastrow*leastcol);
    }
};