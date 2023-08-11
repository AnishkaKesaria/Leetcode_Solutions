class Solution {
public:

    void findCombo(vector<string> &ans, string output, int index, string digits, vector<string> &v)
    {
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string val = v[digit];
        for(int i=0; i<val.length(); i++)
        {
            //include
            char ch = val[i];
            output.push_back(ch);
            findCombo(ans, output, index+1, digits, v);
            output.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};

        vector<string> ans;
        int index = 0;
        string output = "";
        vector<string> v(10);
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
        findCombo(ans, output, index, digits, v);
        return ans;
    }
};