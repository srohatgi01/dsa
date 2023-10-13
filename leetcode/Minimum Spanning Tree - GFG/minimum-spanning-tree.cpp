//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint {
    private:
        vector<int> parent, rank;

    public: 
        Disjoint(int n) {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            // making every element it's own parent
            for(int i = 0; i < n+1; i++) parent[i] = i;
        }

        int findUParent(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulu = findUParent(u);
            int ulv = findUParent(v);

            if(ulu == ulv) return;
            if(rank[ulu] < rank[ulv]) {
                parent[ulu] = ulv;
            }
            else if(rank[ulv] < rank[ulu]) {
                parent[ulv] = ulu;
            }
            else {
                parent[ulv] = ulu;
                rank[ulu]++;
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        Disjoint ds(V);
        int mWt = 0;
        
        for(auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUParent(u) != ds.findUParent(v)) {
                mWt += wt;
                ds.unionByRank(u, v);
            }
        }
        
        return mWt;
    }
    
    // Prim's algorithm
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     int sum = 0;
        
    //     priority_queue<pair<int, int>, 
    //         vector<pair<int, int>>, 
    //         greater<pair<int, int>>> pq;
            
    //     vector<int> vis(V, 0);
        
    //     pq.push( {0, 0});
        
    //     while(!pq.empty()) {
    //         int wt = pq.top().first;
    //         int node = pq.top().second;
    //         pq.pop();
            
    //         if(vis[node] == 1) continue;
    //         vis[node] = 1;
    //         sum += wt;
            
    //         for(auto it: adj[node]) {
    //             int adjNode = it[0];
    //             int edW = it[1];
    //             if(!vis[adjNode]) {
    //                 pq.push({edW, adjNode});
    //             }
    //         }
    //     }
        
    //     return sum;
    // }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends