class Solution {
public:
    bool isPossible(int testWeight, vector<int>& weights, int days) {
        int currDay = 1, load = 0;
        int day = 1;
        for(int i=0; i<weights.size(); i++) {
            if(load+weights[i]>testWeight){
                day++;
                load = weights[i];
                if(day>days)
                    return false;
            } else {
                load += weights[i];
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity = 0, minCapacity = 0;
        for(auto i: weights) {
            maxCapacity += i;
            minCapacity = max(minCapacity, i);
        }

        int start = minCapacity, end = maxCapacity;
        int leastCapacity = maxCapacity;

        while(start<=end) {
            int testWeight = (start+end)/2;

            if(isPossible(testWeight, weights, days)) {
                leastCapacity = testWeight;
                end = testWeight -1;
            } else {
                start = testWeight +1;
            }
        }

        return leastCapacity;
    }
};