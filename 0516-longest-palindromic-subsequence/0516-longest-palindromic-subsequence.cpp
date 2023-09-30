class Solution {
public:
    int longestCommonSubsequence(string text1, string text2, int i, int j)
    {

        if(i>=text1.size()||j>=text2.size())
            return 0;


        if(text1[i]==text2[j])
            return (1+longestCommonSubsequence(text1, text2, i+1, j+1));
        else
        {
            return (max(longestCommonSubsequence(text1, text2, i+1, j),longestCommonSubsequence(text1, text2, i, j+1)));
        }
    }

    int solveSO(string &text1, string &text2)
    {
        int k = max(text1.size(), text2.size());

        vector<int> curr (k+1, 0);
        vector<int> next (k+1, 0);

        for(int i=text1.size()-1; i>=0; i--)
        {
            for(int j=text2.size()-1; j>=0; j--)
            {
                int ans;

                if(text1[i]==text2[j])
                    ans = 1+next[j+1];
                else
                    ans = max(curr[j+1],next[j]);

                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;

        int i=0;
        int j=0;
        int ans = solveSO(text1, text2);
        return ans;
    }
};