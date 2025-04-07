class Solution {
public:
    bool isPossible(int day, vector<int>& bloomDay, int m, int k) {
        int count = 0;
        int b = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i]<=day)
            {
                count++;
                if(count%k==0)
                    b++;
            }
            else
                count = 0;
        }
        return (b>=m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())
            return -1;

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(int i=0; i<bloomDay.size(); i++) {
            maxVal = max(maxVal, bloomDay[i]);
            minVal = min(minVal, bloomDay[i]);
        }

        int minDay = maxVal;
        int start = minVal, end = maxVal;

        while(start<=end) {
            int mid = (start+end)/2;
            if(isPossible(mid, bloomDay, m, k)) {
                minDay = min(mid, minDay);
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return minDay;
    }
};