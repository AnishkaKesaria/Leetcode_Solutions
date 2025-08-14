class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i: nums) {
            currSum += i;
            if(currSum>=maxSum) {
                maxSum = currSum;
            }
            if(currSum<0)
                currSum = 0;
        }

        return maxSum;
    }
};