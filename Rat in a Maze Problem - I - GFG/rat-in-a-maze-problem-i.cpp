//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void findingPath(vector<vector<int>> &m, vector<vector<bool>>& visited, vector<string>& paths, string output, int i, int j, int n)
    {
        if(i==n-1 && j==n-1)
        {
            paths.push_back(output);
            return;
        }
        
        //Down
        if(i+1<n && m[i+1][j]==1 && visited[i+1][j]!=true)
        {
            visited[i+1][j] = true;
            findingPath(m, visited, paths, output+'D', i+1, j, n);
            visited[i+1][j] = false;
        }
        
        //Left
        if(j-1>=0 && m[i][j-1]==1 && visited[i][j-1]!=true)
        {
            visited[i][j-1] = true;
            findingPath(m, visited, paths, output+'L', i, j-1, n);
            visited[i][j-1] = false;
        }
        
        //Right
        if(j+1<n && m[i][j+1]==1 && visited[i][j+1]!=true)
        {
            visited[i][j+1] = true;
            findingPath(m, visited, paths, output+'R', i, j+1, n);
            visited[i][j+1] = false;
        }
        
        //Up
        if(i-1>=0 && m[i-1][j]==1 && visited[i-1][j]!=true)
        {
            visited[i-1][j] = true;
            findingPath(m, visited, paths, output+'U', i-1, j, n);
            visited[i-1][j] = false;
        }
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> paths;
        
        if(m[0][0]==0)
            return paths;
        
        string output = "";
        int i=0, j=0;
        
        vector<vector<bool>> visited(n, vector<bool> (n,false));
        visited[0][0] = true;
        
        findingPath(m, visited, paths, output, i, j, n);
        return paths;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends