class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        typedef vector<vector<int>> vector2d;
        
        vector2d res;
         res.push_back({1});
        if(numRows==1) return res;
         res.push_back({1,1});
        if(numRows==2) return res;
        
        
        for(int i = 2; i < numRows; i++) {
            vector<int> row(i+1, 1);
            // cout<< i<<",";
            
            for(int j = 1; j < i; j++) {
                // cout<<":"<<j<<",";
                // cout<<res[i-1][j-1]<<","<<res[i-1][j]<<"-";
                row[j] = res[i-1][j-1] + res[i-1][j];
            }
            // cout<<endl;
            res.push_back(row);
        }
        
        return res;
    }
};