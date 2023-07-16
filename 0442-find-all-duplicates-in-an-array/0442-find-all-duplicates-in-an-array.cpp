class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicate;
        
        for(auto i: nums)
        {
            int x = abs(i);

            if(nums[x-1]>0)
                nums[x-1] *= -1;
            else
                duplicate.push_back(x);
                
        }

        return duplicate;
    }
};