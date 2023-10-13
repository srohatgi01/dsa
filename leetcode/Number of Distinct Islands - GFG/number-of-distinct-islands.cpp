//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>> &mat, vector<vector<int>> &visited, vector<pair<int, int>> &vec, 
    int row, int col, int row0, int col0) {
            
        visited[row][col] = 1;
        
        vec.push_back({row-row0, col-col0});
        // cout << row << " " << col << endl;
        // cout << row-row0 << " " << col-col0 << endl;
        
        int n = mat.size(), m = mat[0].size();
        
        int x[] = {0, -1, 0, 1};
        int y[] = {1, 0, -1, 0};
        
        for(int i = 0; i < 4; i++) {
            int delRow = row + x[i];
            int delCol = col + y[i];
            
            if(delRow < n && delCol < m && delRow >= 0 && delCol >= 0 && mat[delRow][delCol] == 1  && !visited[delRow][delCol]) {
                dfs(mat, visited, vec, delRow, delCol, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        set<vector<pair<int, int>>> islands = {};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mat = grid, vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && !vis[i][j]) {
                 
                    vector<pair<int, int>> vec;
                    
                    dfs(grid, vis, vec, i, j, i, j);
                 
                   
                    islands.insert(vec);
                }
            }
        }
        
        return islands.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends