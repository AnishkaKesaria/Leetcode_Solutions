class Solution {
public:
    struct cmp {
        bool operator()(string &a, string &b)  {
            if(a.size()==b.size())
                return (a>b);
            return (a.size()>b.size());
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> minHeap;

        for(auto i:nums) {
            minHeap.push(i);
            if(minHeap.size()>k) 
                minHeap.pop();
        }

        return minHeap.top();
    }
};