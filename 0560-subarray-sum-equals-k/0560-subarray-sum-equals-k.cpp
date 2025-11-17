class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1 && k==0 && nums[0]!=0)
            return 0;

        unordered_map<int,int> pMap;
        int currSum = 0;
        pMap[currSum]++;
        int count = 0;
        for(auto i: nums) {
            currSum += i;
            int target = currSum - k;
            count += pMap[target];
            pMap[currSum]++;
        }

        return count;
    }
};