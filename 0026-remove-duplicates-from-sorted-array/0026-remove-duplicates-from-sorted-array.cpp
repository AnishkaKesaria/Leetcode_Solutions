class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int key;
        for(int i=1; i<nums.size(); i++)
        {
            key = nums[k-1];
            while(i<nums.size() && nums[i]==key)
            {
                i++;
            }
            if(i<nums.size())
                swap(nums[k++], nums[i]);
        }
        return k;
    }
};