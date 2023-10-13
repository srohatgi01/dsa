//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int, int>> adj[n];
        
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        dist[src] = 0;
        
        while(!q.empty()) {
            int stop = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            
            if(stop > K) continue;
            
            for(auto it: adj[node]) {
                if(dis + it.second < dist[it.first]) {
                    dist[it.first] = dis + it.second;
                    q.push({stop+1, {it.first, it.second + dis}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends