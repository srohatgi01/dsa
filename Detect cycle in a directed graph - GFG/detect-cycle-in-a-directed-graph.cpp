//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(vector<int> adj[], vector<int> &visited, vector<int> &pathvisited, int node) {
        visited[node] = 1;
        pathvisited[node] = 1;
        
        int n = adj[node].size();
        
        for(int i = 0; i < n; i++) {
            if(!visited[adj[node][i]]) {
                bool hasCycle = dfs(adj, visited, pathvisited, adj[node][i]);
                if(hasCycle == true) return true;
            }
            
            else if(pathvisited[adj[node][i]]) return true;
        }
        
        pathvisited[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), pathvisited(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(adj, visited, pathvisited, i) == true) return true;
            }
        }
        // for(auto i : visited) cout << i << " ";
        // cout << endl;
        // for(auto i : pathvisited) cout << i << " ";
        // cout << endl;
        
        return false;
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