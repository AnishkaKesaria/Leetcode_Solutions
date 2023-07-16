class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> originalArray;
        if(changed.size()%2!=0)
            return originalArray;
        sort(changed.begin(), changed.end(), greater<int>());

        map<int,int> mp;
        for(int i=0; i<changed.size(); i++)
        {
            if(mp.find(changed[i]*2)!=mp.end())
            {
                if(mp[changed[i]*2]>0)
                    mp[changed[i]*2]--;
                originalArray.push_back(changed[i]);
                if(mp[changed[i]*2]==0)
                    mp.erase(changed[i]*2);
            }

            else
                mp[changed[i]]++;
        }

        for(auto val: mp)
        {
            if(val.second!=0)
                return {};
        }
        
        return originalArray;
    }
};