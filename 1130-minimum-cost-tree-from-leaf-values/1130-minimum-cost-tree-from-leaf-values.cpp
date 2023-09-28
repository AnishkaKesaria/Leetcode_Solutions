class Solution {
public:
    int solve(int left, int right, map<pair<int,int>, int> maxi, vector<int> &arr)
    {
        if(left>=right)
            return 0;
        

        int ans = INT_MAX;

        for(int i=left; i<right; i++)
        {
            if(i+1<=arr.size()-1)
                ans = min(ans, (maxi[{left,i}]*maxi[{i+1, right}]) + solve(left,i,maxi,arr) + solve(i+1, right, maxi, arr) );
        }

        if(ans==INT_MAX)
            return 0;

        return ans;
    }

    int solveUsingMem(int left, int right, vector<vector<int>> &dp, map<pair<int,int>, int> &maxi, vector<int> &arr)
    {
        if(left>=right)
            return 0;
        
        if(dp[left][right]!=INT_MAX)
            return dp[left][right];

        int ans = INT_MAX;

        for(int i=left; i<right; i++)
        {
            if(i+1<=arr.size()-1)
                ans = min(ans, (maxi[{left,i}]*maxi[{i+1, right}]) + solveUsingMem(left,i,dp,maxi,arr) + solveUsingMem(i+1, right,dp, maxi, arr) );
        }

        if(ans==INT_MAX)
            ans = 0;

        dp[left][right] = ans;
        return dp[left][right];
    }

    int solveUsingTab(map<pair<int,int>, int> maxi, vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int left= n-1; left>=0; left--)
        {
            for(int right = 0; right<n; right++)
            {
                int ans = INT_MAX;
                for(int i=left; i<right; i++)
                {
                    if(i+1<=arr.size()-1)
                        ans = min(ans, (maxi[{left,i}]*maxi[{i+1, right}]) + dp[left][i] + dp[i+1][right] );
                }

                if(ans==INT_MAX)
                    ans = 0;

                dp[left][right] = ans;
            }
        }
        return dp[0][n-1];

    } 

    int mctFromLeafValues(vector<int>& arr) {

        map< pair<int,int>, int> maxi;

        for(int i=0; i<arr.size(); i++)
        {
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j<arr.size(); j++)
            {
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        int n = arr.size();

        vector<vector<int>> dp (n, vector<int> (n, INT_MAX));
    
        int left = 0;
        int right = arr.size()-1;

        int ans = solveUsingTab(maxi, arr);

        // int ans = solve(left, right, maxi, arr);
        return ans;
    }
};