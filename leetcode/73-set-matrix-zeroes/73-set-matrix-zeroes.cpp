class Solution {
public:
    
    bool findElement(vector<int> arr, int element) {
        int size = arr.size();
        for(int i = 0; i < size; i++) {
            if(arr[i] == element) return true;
        }
        
        return false;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows, cols;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j]==0) {
                    // vector<int>::iterator f1 = find(rows.begin(), rows.end(), j);
                    // if(f1 == rows.end()) rows.push_back(j);
                    // vector<int>::iterator f2 = find(cols.begin(), rows.end(), i);
                    // if(f2 == cols.end()) cols.push_back(i);
                    if(!findElement(rows, j)) {
                        rows.push_back(j);
                    }
                    if(!findElement(cols, i)) {
                        cols.push_back(i);
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(findElement(rows, j)) {
                    matrix[i][j] = 0;
                }
                
                if(findElement(cols, i)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};