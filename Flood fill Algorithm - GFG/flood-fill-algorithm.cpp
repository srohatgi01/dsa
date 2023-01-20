//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    void helper(vector<vector<int>> &image, vector<vector<int>> &visited, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int cor = image[sr][sc];
        visited[sr][sc] = 1;
        image[sr][sc] = newColor;
        
        //for the neighbouring nodes (horizontally & vertically only)
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 || j == 0) {
                    int newSr = sr + i;
                    int newSc = sc + j;
                    if(newSr < n && newSc < m && newSr >= 0 && newSc >= 0 && image[newSr][newSc] == cor && !visited[newSr][newSc]) {
                        helper(image, visited, newSr, newSc, newColor);
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        helper(image, visited, sr, sc, newColor);
        /*
            111
            110
            101
        */
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends