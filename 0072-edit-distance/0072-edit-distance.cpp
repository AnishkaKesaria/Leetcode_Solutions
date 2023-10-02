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

    int solveUsingTab(string word1, string word2)
    {
        int k = max(word1.size(), word2.size());
        // vector<vector<int>> dp(k+2, vector<int> (k+2, 0));
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, 0));

        for(int j=0; j<word2.size(); j++)
        {
            dp[word1.size()][j] = word2.size()-j;
        }

        for(int i=0; i<word1.size(); i++)
        {
            dp[i][word2.size()] = word1.size()-i;
        }

        // int n1 = word1.size();
        // int n2 = word2.size();

        // for(int i=n1; i<=k; i++)
        // {
        //     for(int j=0; j<=k; j++)
        //     {
        //         if(j>=n2)
        //         {
        //             dp[i][j] = 0;
        //         }
        //         else
        //         {
        //             dp[i][j] = n2-j;
        //         }
        //     }
        // }

        // for(int j=n2; j<=k; j++)
        // {
        //     for(int i=0; i<=k; i++)
        //     {
        //         if(i>=n1)
        //             dp[i][j] = 0;
        //         else
        //             dp[i][j] = n1-i;
        //     }
        // }

        for(int i=word1.size()-1; i>=0; i--)
        {
            for(int j=word2.size()-1; j>=0; j--)
            {
                int ans;

                if(word1[i]==word2[j])
                    ans = dp[i+1][j+1];

                else
                {
                    int insertOp = 1 + dp[i][j+1];
                    int deleteOp = 1 + dp[i+1][j];
                    int replaceOp = 1 + dp[i+1][j+1];
                    ans = (min(insertOp, min(deleteOp, replaceOp)));
                }

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    

    int minDistance(string word1, string word2) {
        if(word1.size()==0 || word2.size()==0)
            return max(word1.size(), word2.size());

        int i = 0;
        int j = 0;

        int k = max(word1.size(), word2.size());

        vector<vector<int>> dp(k+1, vector<int> (k+1, -1));
        // int ans = solveUsingMem(word1, word2, i, j, dp);
        int ans = solveUsingTab(word1, word2);


        // int ans = solveUsingRec(word1, word2, i, j);
        return ans;
    }
};