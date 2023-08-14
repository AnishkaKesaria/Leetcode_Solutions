class Solution {
public:
    int findDuplicate(vector<int>& num) {
        unordered_map<int,int> m;
        for(int i=0; i<num.size(); i++)
        {
            m[num[i]]++;
        }

        for(auto i: m)
        {
            if(i.second>1)
                return i.first;
        }
        return -1;
    }
};