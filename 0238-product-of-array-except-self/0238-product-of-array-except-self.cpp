class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size(), 1);
        int prefixVal = 1;
        for(int i=0; i<nums.size()-1; i++) {
            prefixVal *= nums[i];
            ans[i+1] = prefixVal;
        }
        int postfixVal = 1;
        for(int i=nums.size()-1; i>0; i--) {
            postfixVal *= nums[i];
            ans[i-1] *= postfixVal;
        }

        return ans;
    }
};