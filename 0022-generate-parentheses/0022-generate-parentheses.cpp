class Solution {
public:
    void findParenthesis(vector<string> &ans, string output, int open, int close)
    {
        if(open==0 && close==0)
        {
            ans.push_back(output);
            return;
        }

        //include open
        if(open>0)
            findParenthesis(ans, output+'(', open-1, close);

        if(close>open)
            findParenthesis(ans, output+')', open, close-1);

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = n, close = n;
        findParenthesis(ans, output, open, close);
        return ans;
    }
};