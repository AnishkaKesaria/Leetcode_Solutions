//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int capacity, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int> (capacity+1, 0));
       
       for(int w = wt[0]; w<=capacity; w++)
       {
           if(wt[0]<=capacity)
              dp[0][w] = val[0];
           else
              dp[0][w] = 0;
       }
       
       for(int i=1; i<n; i++)
       {
           for(int w=0; w<=capacity; w++)
           {
               int include = 0;
               if(wt[i]<=w)
                   include = val[i] + dp[i-1][w-wt[i]];
               int exclude = dp[i-1][w];
               
               dp[i][w] = max(include,exclude);
           }
       }
       
       return dp[n-1][capacity];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends