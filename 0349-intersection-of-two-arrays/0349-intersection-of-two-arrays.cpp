class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto num: nums1)
        {
            m[num]++;
        }

        vector<int> ans;
        for(auto num: nums2)
        {
            if(m.find(num)!=m.end())
            {
                ans.push_back(num);
                m.erase(num);
            }
        }
        return ans;
    }
};