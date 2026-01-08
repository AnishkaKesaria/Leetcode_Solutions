class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long windowSum = 0;
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
            windowSum += nums[i];

            if(i>=k) {
                windowSum -= nums[i-k];
                freq[nums[i-k]]--;
                if(freq[nums[i-k]]==0)
                    freq.erase(nums[i-k]);
            }

            if(i>=k-1 && freq.size()==k)
                maxSum = max(maxSum,windowSum);
        }

        return maxSum;
    }
};