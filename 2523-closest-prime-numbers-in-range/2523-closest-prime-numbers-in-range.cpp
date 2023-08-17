class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        vector<int> prime;
        isPrime[1] = false;
        for(int i=2; i<isPrime.size(); i++)
        {
            if(isPrime[i]==true)
            {
                if(i>= left)
                    prime.push_back(i);
                for(int j=i*2; j<=isPrime.size(); j+=i)
                {
                    isPrime[j] = false;
                }
            }
            else
                continue;
        }

        int mini = INT_MAX;
        vector<int> ans = {-1,-1};

        for(int i=1; i<prime.size(); i++)
        {
            if(prime[i] - prime[i-1]<mini)
            {
                mini = prime[i] - prime[i-1];
                ans[0] = prime[i-1];
                ans[1] = prime[i];
            }
        }

        return ans;
    }
};