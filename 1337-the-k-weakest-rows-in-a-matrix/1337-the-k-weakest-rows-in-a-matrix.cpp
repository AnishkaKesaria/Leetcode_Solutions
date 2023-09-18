class Solution {
public:
    int findCount(vector<int> &row)
    {
        int l = 0, r = row.size()-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(row[mid]==1)
                l = mid+1;
            else
                r = mid-1;
        }

        return l;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        for(int i=0; i<mat.size(); i++)
        {
            int soldierCount = findCount(mat[i]);
            minHeap.push(make_pair(soldierCount, i));
        }

        vector<int> kWeak;
        for(int i=0; i<k; i++)
        {
            kWeak.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return kWeak;
    }
};