class Solution {
public:
    vector<int> mergeArray(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ansArray;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        int index = 0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
                ansArray.push_back(nums1[i++]);
            else
                ansArray.push_back(nums2[j++]);
        }

        while(i<n1)
        {
            ansArray.push_back(nums1[i++]);
        }

        while(j<n2)
        {
            ansArray.push_back(nums2[j++]);
        }

        return ansArray;
    }

    double findMedian(vector<int> &arr)
    {
        double median;
        int n = arr.size();
        
        if(n%2==1)
            median = arr[(n/2)];
        else
        {
            median = (arr[(n/2)-1] + arr[n/2])/2.0;
        }

        return median;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        vector<int> arr = mergeArray(nums1, nums2);
        ans = findMedian(arr);
        return ans;
    }
};