class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int midIndex = n/2;
        int i=0;
        int p1=0, p2=0;
        int ith=0, jth=0;
        while(i!=midIndex+2) {
            if(p1<nums1.size()) {
                if(p2<nums2.size()) {
                    if(nums1[p1]<nums2[p2]) {
                        if(i==midIndex)
                            ith = nums1[p1];
                        if(i==midIndex-1)
                            jth = nums1[p1];
                        p1++;
                    }
                    else {
                        if(i==midIndex)
                            ith = nums2[p2];
                        if(i==midIndex-1)
                            jth = nums2[p2];
                        p2++;
                    }    
                } else {
                    if(i==midIndex)
                            ith = nums1[p1];
                        if(i==midIndex-1)
                            jth = nums1[p1];
                    p1++;
                }
            } else if (p2<nums2.size()) {
                if(i==midIndex)
                    ith = nums2[p2];
                if(i==midIndex-1)
                    jth = nums2[p2];
                p2++; 
            }
            i++;
        }

        if(n%2==0)
            return ((double)(ith+jth)/2);
        else
            return ith;
    }
};