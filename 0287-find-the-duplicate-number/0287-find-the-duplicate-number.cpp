class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 1;
        int h = len-1;

        while(l<h)
        {
            int mid = l + (h-l)/2;
            int count = 0;
            for(auto i: nums)
            {
                if(i<=mid)
                    count++;
            }

            if(count<=mid)
                l = mid+1;
            else
                h = mid;
        }

        return l;
    }
};