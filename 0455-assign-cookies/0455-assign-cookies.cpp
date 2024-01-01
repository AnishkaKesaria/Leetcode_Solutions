class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int j = 0;
        
        for(int i=0;j<g.size() && i<s.size(); i++)
        {
            if(g[j]<=s[i])
                j++;
        }
        
        return j;
    }
};