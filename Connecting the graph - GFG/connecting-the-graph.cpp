//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    int Solve(int n, vector<vector<int>>& edge) {
        Disjoint ds(n);
        int extra = 0, com = 0;
        
        for(auto it: edge) {
            int u = it[0];
            int v = it[1];
            
            if(ds.findUParent(u) != ds.findUParent(v)) {
                ds.unionByRank(u, v);
            }
            else {
                extra++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) {
                com++;
            }
        }
        
        if(extra >= com-1) return com-1;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends