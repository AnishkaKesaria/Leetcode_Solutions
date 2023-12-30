class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        if(n==1)
            return true;

        unordered_map<char,int> m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                m[words[i][j]]++;
            }
        }

        for(auto i: m)
        {   
            if(i.second%n!=0)
                return false;
        }

        return true;
    }
};