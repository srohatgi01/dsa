//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Disjoint {
    public: 
        vector<int> parent, rank;
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

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        Disjoint ds(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < V; i++) {
            if(ds.parent[i] == i) count++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends