class info {
    public:
    int data;
    int row;
    int col;

    info(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
    public:
    bool operator()(info* a, info* b)
    {
        return (a->data>b->data);
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<info*, vector<info*>, compare> pq;

        for(int i=0; i<k; i++)
        {
            maxi = max(maxi, nums[i][0]);
            info* temp = new info(nums[i][0], i, 0);
            pq.push(temp);
        }

        mini = pq.top()->data;
        int diff = maxi - mini;

        vector<int> ans = {mini,maxi};

        while(!pq.empty() && pq.size()==k)
        {
            info* topElement = pq.top();
            int topRow = topElement->row;
            int topCol = topElement->col;
            mini = topElement->data;
            int currDiff = maxi-mini;
            if(currDiff<diff)
            {
                diff = currDiff;
                ans[0] = mini;
                ans[1] = maxi;
            }
            pq.pop();

            if(topCol+1<nums[topRow].size())
            {
                info* temp = new info(nums[topRow][topCol+1], topRow, topCol+1);
                maxi = max(maxi,nums[topRow][topCol+1]);
                pq.push(temp);
            }
        }
        return ans;

    }
};