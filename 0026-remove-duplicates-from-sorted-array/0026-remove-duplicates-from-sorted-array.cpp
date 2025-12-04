class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=nums[i-1] && nums[i]>nums[i-1] && nums[i]>nums[k-1]) {
                k++;
                swap(nums[i], nums[k-1]);
            }
        }
        return k;
    }
};