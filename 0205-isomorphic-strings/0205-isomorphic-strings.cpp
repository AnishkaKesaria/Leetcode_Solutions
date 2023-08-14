class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapstot;
        unordered_map<char,char> mapttos;
        for(int i=0; i<s.size(); i++)
        {
            if(mapttos.find(t[i])!=mapttos.end())
            {
                if(mapttos[t[i]]!=s[i])
                    return false;
            }
            else
                mapttos[t[i]] = s[i];

            if(mapstot.find(s[i])!=mapstot.end())
            {
                if(mapstot[s[i]]!=t[i])
                    return false;
            }
            else
                mapstot[s[i]] = t[i];
        }
        return true;
    }
};