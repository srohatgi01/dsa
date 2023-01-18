//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col) {
        queue<pair<int, int>> q;
        visited[row][col] = 1;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()) {
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();
            
            for(int a = -1; a <= 1; a++) {
                for(int b = -1; b <= 1; b++) {
                    int nRow = frontRow + a;
                    int nCol = frontCol + b;
                    if(nRow < n && nCol < m && nCol >= 0 &&  nRow >= 0 &&  grid[nRow][nCol] == '1' && !visited[nRow][nCol]) {
                        visited[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        } 
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    numberOfIslands++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        
        return numberOfIslands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends