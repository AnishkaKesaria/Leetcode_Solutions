class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> indexes;
        int maxLen = 0;
        for(int i=0; i<s.length(); i++)
        {
            indexes[s[i]].push_back(i+1);
        }
        int flag = 0;
        for(int i=0; i<indexes.size(); i++)
        {
            if(indexes[i].size()>1)
            {
                maxLen = max(maxLen, indexes[i][indexes[i].size()-1]-indexes[i][0]-1);
                flag = 1;
            }
        }

        if(flag==0)
            return -1;

        return maxLen;
    }
};