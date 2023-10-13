//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    int n = prerequisites.size();
	    vector<int> indegree(N, 0);
	    queue<int> q;
	    int res = 0;
	    vector<int> adj[N];
	    for(int i = 0; i < n; i++) {
	        int f = prerequisites[i].first;
	        int s = prerequisites[i].second;
	        
	        adj[f].push_back(s);
	    }
	   
	    //calculating indegree of all the nodes
	    for(int i = 0; i < n; i++) {
	        indegree[prerequisites[i].second]++;
	    }
	    
	    // push the elements with 0 indegree to queue
	    for(int i = 0; i < N; i++) {
	        if(indegree[i] == 0) {
	           // cout << "pushed:" << i << endl; 
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        res++;
	        
	        for(auto it: adj[node]) {
	            
	        
	                indegree[it]--;
	                if(indegree[it] == 0) {
	              
	                q.push(it);
	        
	            }
	            
	            
	        }
	    }
	    
	    if(res == N) return true;
	    else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends