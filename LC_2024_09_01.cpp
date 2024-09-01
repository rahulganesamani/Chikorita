// 2022. Convert 1D Array Into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        if ( m*n != original.size() )
            return result;
        int count = 0;
        for ( int i = 0; i < m; i++ ) {
            vector<int> row;
            for ( int j = 0; j < n; j++ ) {
                row.push_back(original[count]); 
                count++;
            }
            result.push_back(row);
        }
        return result;
    }
};
