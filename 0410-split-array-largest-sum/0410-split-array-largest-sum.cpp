class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int sum) {
        int currSum = 0;
        int count = 1;
        for(int i: nums) {
            if(currSum+i<=sum) {
                currSum += i;
            } else {
                count++;
                currSum = i;
                if(count>k || currSum>sum)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int maxSum = 0;
        int minSum = INT_MAX;
        for(int i: nums) {
            maxSum += i;
            minSum = min(minSum, i);
        }

        int ans = maxSum;
        int s = minSum, e = maxSum;
        while(s<=e) {
            int mid = s + (e-s)/2;
            if(isPossible(nums, k, mid)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};