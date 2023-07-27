class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0; i<piles.size(); i++)
            pq.push(piles[i]);
        


        while(k)
        {
            int newPile = pq.top() - pq.top()/2;
            pq.pop();
            pq.push(newPile);
            k--;
        }

        int sum = 0;
        while(!pq.empty())
        {
            sum+= pq.top();
            pq.pop();
        }

        return sum;
    }
};