//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWaysMem(int n, int k, vector<long long> &dp){
        // code here
        long long mod = 1000000007;
        
        if(n==1)
            return k;
            
        if(n==2)
            return (k + k*(k-1));
            
        if(dp[n]!=-1)
            return dp[n];
            
        long long ans = ((countWaysMem(n-1,k,dp)+countWaysMem(n-2,k,dp))*(k-1)) % mod;
        dp[n] = ans;
        return dp[n];
    }
    
    long long countWays(int n, int k)
    {
        vector<long long> dp(n+1, -1);
        long long ans = countWaysMem(n, k, dp);
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends