class Solution {
public:
    int solveUsingRec(string &word1, string &word2, int i, int j)
    {
        if(i>=word1.size())
        {
            if(j>=word2.size())
                return 0;
            else
                return word2.size()-j;
        }

        if(j>=word2.size())
        {
            if(i>=word1.size())
                return 0;
            else
                return word1.size()-i;
        }

        if(word1[i]==word2[j])
            return solveUsingRec(word1, word2, i+1, j+1);

        else
        {
            int insertOp = 1 + solveUsingRec(word1, word2, i, j+1);
            int deleteOp = 1 + solveUsingRec(word1, word2, i+1, j);
            int replaceOp = 1 + solveUsingRec(word1, word2, i+1, j+1);
            return (min(insertOp, min(deleteOp, replaceOp)));
        }
    }

    int solveUsingMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=word1.size())
        {
            if(j>=word2.size())
                return 0;
            else
                return word2.size()-j;
        }

        if(j>=word2.size())
        {
            if(i>=word1.size())
                return 0;
            else
                return word1.size()-i;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans;

        if(word1[i]==word2[j])
            ans = solveUsingMem(word1, word2, i+1, j+1, dp);

        else
        {
            int insertOp = 1 + solveUsingMem(word1, word2, i, j+1, dp);
            int deleteOp = 1 + solveUsingMem(word1, word2, i+1, j, dp);
            int replaceOp = 1 + solveUsingMem(word1, word2, i+1, j+1, dp);
            ans = (min(insertOp, min(deleteOp, replaceOp)));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    

    int minDistance(string word1, string word2) {
        if(word1.size()==0 || word2.size()==0)
            return max(word1.size(), word2.size());

        int i = 0;
        int j = 0;

        int k = max(word1.size(), word2.size());

        vector<vector<int>> dp(k+1, vector<int> (k+1, -1));
        int ans = solveUsingMem(word1, word2, i, j, dp);

        // int ans = solveUsingRec(word1, word2, i, j);
        return ans;
    }
};