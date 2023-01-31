//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  private:
    void dfs(vector<vector<int>> &grid, int i, int j) {
        // cout << i << j << " ";
        grid[i][j] = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        int x[] = {0, -1, 0, 1};
        int y[] = {1, 0, -1, 0};
        
        for(int k = 0; k < 4; k++) {
            int newRow = i + x[k];
            int newCol = j + y[k];
            
            if(newRow < n && newCol < m && newRow >= 0 && newCol >= 0 && grid[newRow][newCol] == 1) dfs(grid, newRow, newCol);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<int>> mat = grid;
        int enclaves = 0;
        
        // matrix parameteres
        int n = grid.size();
        int m = grid[0].size();
        
        // traverse boundaries
        for(int i = 0; i < m; i++) {
            if(mat[0][i] == 1) dfs(mat, 0, i);
        }
        
        for(int i = 1; i < n; i++) {
            if(mat[i][m-1] == 1) dfs(mat, i, m-1);
        }
        if(m > 1)
        for(int i = m-2; i >= 0; i--) {
            if(mat[n-1][i] == 1) dfs(mat, n-1, i);
        }
        
        if(n > 1)
        for(int i = n-2; i > 0; i--) {
            if(mat[i][0] == 1) dfs(mat, i, 0);
        }
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // cout << mat[i][j];
                if(mat[i][j] == 1) {
                    enclaves++;
                    // cout << mat[i][j] << " ";
                }
            }
            // cout << endl;
        }
        
        return enclaves;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends