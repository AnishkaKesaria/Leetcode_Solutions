class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        reverse(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }

        vector<vector<int>> ans;

            int flag =0;

            while(flag!=m.size())
            {
                vector<int> temp;
                for(auto it = m.begin(); it!= m.end(); it++)
                {
                    if(it->second!=0)
                    {
                        temp.push_back(it->first);
                        it->second--;
                        if(it->second==0)
                            flag++;
                    }
                }
                // reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }

        return ans;
    }
};