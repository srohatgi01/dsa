//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // here we will do topological sorting
        // using kahn's algorithm
        
        vector<int> inDegree(V, 0);
        queue<int> q;
        int n = 0, res = 0;
        
        //calculate all the indegree of the nodes
        for(int i = 0; i < V; i++) {
            n = adj[i].size();
            for(int j = 0; j < n; j++) {
                inDegree[adj[i][j]]++;
            }
        }
        
        //check all the nodes with 0 as indegree and push in the queue
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res++;
            
            for(auto it: adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
            
           
            
        }
        
        if(res == V) {
                return false;
            }
        else {
           return true;
        }
        
        
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