//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycleDetectDFS(int src, vector<int> adj[], unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;
        for(auto neighbour: adj[src])
        {
            if(!visited[neighbour])
            {
                int ans = cycleDetectDFS(neighbour, adj, visited, src);
                if(ans==true)
                    return true;
            }
            else
            {
                if(neighbour!=parent)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visited;
        
        bool ans = false;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                ans = cycleDetectDFS(i, adj, visited, -1);
                if(ans==true)
                    return true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends