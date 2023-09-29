class Solution {
public:
    int solveUsingRec(string text1, string text2, int i, int j)
    {
        if(i>=text1.size() || j>=text2.size())
            return 0;

        //char matched
        if(text1[i]==text2[j])
        {
            return (1+solveUsingRec(text1, text2, i+1, j+1));
        }
        //char not matched
        else
        {
            return (max(solveUsingRec(text1, text2, i, j+1), solveUsingRec(text1, text2, i+1, j)));
        }
    }

    int solveUsingMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=text1.size() || j>=text2.size())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans;

        if(text1[i]==text2[j])
            ans = (1+solveUsingMem(text1, text2, i+1, j+1, dp));
        else
            ans = max(solveUsingMem(text1, text2, i, j+1, dp), solveUsingMem(text1, text2, i+1, j, dp));

        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        int ans = solveUsingMem(text1, text2, 0, 0, dp);
        // int ans = solveUsingRec(text1, text2, 0, 0);
        return ans;
    }
};