//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>> dupgrid = grid;
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> visited(n, vector<int>(m, 0)), distance(n, vector<int>(m, 0));
	    
	    // traverse all the positions with 1 and push into the queue
	    queue<pair<pair<int,int>, int>> q;
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(dupgrid[i][j] == 1 && !visited[i][j]) {
	                q.push({{i, j}, 0});
	               // cout << "{{" << i << "," << j<<"}," << 0 <<"}" << " | ";
	               // visited[i][j] = 1;
	            }
	        }
	    }
	    
	    while(!q.empty()) {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        
	       // visited[row][col] = 1;
	        distance[row][col] = d;
	        
	        int x[] = {0, -1, 0, 1};
	        int y[] = {1, 0, -1, 0};
	        
	        for(int i = 0; i < 4; i++) {
	            int delRow = row + x[i];
	            int delCol = col + y[i];
	            
    	        

	            
	            if(delRow < n && delCol < m && delRow >= 0 && delCol >= 0 && !visited[delRow][delCol]&& 
	               dupgrid[delRow][delCol] == 0) {
	               //cout << "{{" << delRow << "," << delCol<<"}," << d+1 <<"}" << " | ";
	                q.push({{delRow, delCol}, d+1});
	                visited[delRow][delCol] = 1;
	            }
	        }
	    }
	    
	    return distance;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends