class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = 1;
        while(i<(nums.size()-1)) {
            if(i>0 && nums[i]==nums[i-1])
            {
                i++;
                j = i+1;
                continue;
            } else {
                //cout<<nums[j]<<" "<<nums[i]<<endl;
                //cout<<"diff "<<nums[j]-nums[i]<<endl;
            if(nums[j]-nums[i]==k) {
                //cout<<"Equals "<<nums[j] <<" "<<nums[i]<<endl;
                count++;
                i++;
                j=i+1;
            } 
            else if (nums[j]-nums[i]<k) {
                //cout<<"Lesser "<<nums[j] <<" "<<nums[i]<<endl;
                j++;
                if(j>nums.size()-1) {
                    i++;
                    j = i+1;
                }
            } else {
                i++;
                j = i+1;
            }
        }
        }

        return count;
    }
};