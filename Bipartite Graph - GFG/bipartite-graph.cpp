//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int V, vector<int>adj[], int start, vector<int> &color) {
        queue<int> q;
	    q.push(start);
	    color[start] = 0;
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        int n = adj[node].size();
	        int c = color[node];
	        
	        for(int i = 0; i < n; i++) {
	            if(color[adj[node][i]] == -1) {
	                color[adj[node][i]] = !color[node];
	                q.push(adj[node][i]);
	            }
	            else if(color[adj[node][i]] == color[node]) {
	                return false;
	            }
	        }
	    }
	    
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    for(int i = 0; i < V; i++ ) {
	        if(color[i] == -1){
	        if(check(V, adj, i, color) == false) return false;
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