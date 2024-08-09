// 840. Magic Squares In Grid

class Solution {
public:
    bool checkMatrix(vector<vector<int>>& grid, int a, int b) {
        int r1 = 0; 
        int r2 = 0; 
        int r3 = 0;
        int c1 = 0; 
        int c2 = 0;
        int c3 = 0;
        int d1 = 0;
        int d2 = 0;
        vector<int> numCheck(9,0);
        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                if ( grid[a+i][b+j] > 9 || grid[a+i][b+j] < 1 )
                    return false;
                if ( numCheck[grid[a+i][b+j]-1] > 0 )
                    return false;
                numCheck[grid[a+i][b+j]-1]++;
            }
        }
        for ( int i = 0; i < 3; i++ ) {
            r1 += grid[a][b+i];
            r2 += grid[a+1][b+i];
            r3 += grid[a+2][b+i];
            c1 += grid[a+i][b];
            c2 += grid[a+i][b+1];
            c3 += grid[a+i][b+2];
            d1 += grid[a+i][b+i];
            d2 += grid[a+i][b+2-i];
        }
        return ( r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2 );
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        if ( grid.size() < 3 || grid[0].size() < 3  )
            return 0;
        for ( int i = 0; i < (grid.size()-2); i++ ) {
            for ( int j = 0; j < (grid[0].size()-2); j++ ) {
                if ( checkMatrix(grid, i, j) )
                    count += 1;
            } 
        }
        return count;
    }
};
