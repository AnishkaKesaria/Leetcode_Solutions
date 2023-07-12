class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0; i<nums.size()-2; i++)
        {
            int s = i+1;
            int e = nums.size()-1;
            while(s<e)
            {
                if(nums[i]+nums[s]+nums[e]==0)
                {
                    //vector<int> temp = {nums[i], nums[s], nums[e]};
                    st.insert({nums[i], nums[s], nums[e]});
                    //continue;
                    s++;
                    e--;
                    continue;
                }

                if(nums[i]+nums[s]+nums[e] < 0)
                    s++;
                else
                    e--;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};