//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, source});
        
        while(!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            if(row == destination.first && col == destination.second) return dis;
            
            int x[] = {0, 1, 0, -1};
            int y[] = {1, 0, -1, 0};
            
            for(int i = 0; i < 4; i++) {
                int delRow = row + x[i];
                int delCol = col + y[i];
                
                if(delRow >= 0 && delRow < n && delCol >= 0 && delCol < m && grid[delRow][delCol] != 0) {
                    if(dis + 1 < dist[delRow][delCol]) {
                        dist[delRow][delCol] = dis + 1;
                        q.push({dis+1, {delRow, delCol}});
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends