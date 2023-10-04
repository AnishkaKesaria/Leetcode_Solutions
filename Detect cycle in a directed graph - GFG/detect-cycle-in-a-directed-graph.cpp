//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclicDFS(int src, vector<int> adj[], unordered_map<int,bool> &visited, unordered_map<int,bool> &DFSVisited)
    {
        visited[src] = true;
        DFSVisited[src] = true;
        
        for(auto neighbour: adj[src])
        {
            if(!visited[neighbour])
            {
                int ans = isCyclicDFS(neighbour, adj, visited, DFSVisited);
                if(ans==true)
                    return true;
            }
            else
            {
                if(DFSVisited[neighbour]==true)
                    return true;
            }
        }
        
        DFSVisited[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int,bool> visited;
        unordered_map<int,bool> DFSVisited;
        
        int ans = false;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                ans = isCyclicDFS(i, adj, visited, DFSVisited);
                if(ans==true)
                    return ans;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends