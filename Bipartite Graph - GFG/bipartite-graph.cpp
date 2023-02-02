//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(vector<int>adj[], vector<int> &color, int node, int c) {
        color[node] = c;
        int size = adj[node].size();
        for(int i = 0; i < size; i++) {
            if(color[adj[node][i]] == -1) {
                if(dfs(adj, color, adj[node][i], !c) == false) return false;
            }
            else if(color[adj[node][i]] != -1 && color[adj[node][i]] == color[node]) {
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            if(dfs(adj, color, i, 0) == false) return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends