class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        for(int i=n-1; i>=0; i--)
        {
            if(num[i]=='0')   continue;
            else
                return num.substr(0,i+1);
        }
        return "";
    }
};