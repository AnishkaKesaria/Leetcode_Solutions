class Solution {
public:
    int findUniquePaths(int i, int j, int m, int n) {
        if(i==m-1 && j==n-1)
            return 1;
        else if(i>=m || j>=n)
            return 0;

        //go down
        int down = findUniquePaths(i+1, j, m, n);
        //go right
        int right = findUniquePaths(i, j+1, m, n);

        return (right+down);
    }

    int findUniquePathsDP(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i==m-1 && j==n-1)
            return 1;
        else if(i>=m || j>=n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        //go down
        int down = findUniquePathsDP(i+1, j, m, n, dp);
        //go right
        int right = findUniquePathsDP(i, j+1, m, n, dp);

        dp[i][j] = right+down;
        return dp[i][j];
    }


    int uniquePaths(int m, int n) {
        int i=0, j = 0;
        vector<vector<int>> dp(m, vector<int> (n,-1));


        // int ans = findUniquePaths(i, j, m, n);
        int ans = findUniquePathsDP(i, j, m, n, dp);
        return ans;
    }
};