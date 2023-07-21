class Solution {
public:

    void heapify(vector<int> &nums, int n, int i)
    {
        int index = i;
        int leftIndex = 2*i + 1;
        int rightIndex = 2*i + 2;

        int largest = index;
        if(leftIndex<n && nums[largest]<nums[leftIndex])
            largest = leftIndex;
        if(rightIndex<n && nums[largest]<nums[rightIndex])
            largest = rightIndex;

        if(largest!=index)
        {
            swap(nums[largest], nums[index]);
            index = largest;
            heapify(nums, n, index);
        }
        return;
    }

    void buildHeap(vector<int> &nums, int n)
    {
        for(int i= n/2 - 1; i>=0; i--)
        {
            heapify(nums, n, i);
        }
        return;
    }

    void heapSort(vector<int> &nums, int n)
    {
        while(n>0)
        {
            swap(nums[0], nums[n]);
            n--;
            heapify(nums, n+1, 0);
        }
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        buildHeap(nums,nums.size());
        heapSort(nums,nums.size()-1);
        return nums;
    }
};