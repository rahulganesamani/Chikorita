// 769. Max Chunks To Make Sorted

class Solution {
public:
    bool checkAllNums( vector<int>& arr, int start, int end  ) {
        for ( int i = start; i <= end; i++ ) {
            if ( arr[i] < start || arr[i] > end )
                return false;
        }
        return true;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int numChunks = 0;
        int start = 0;
        for ( int i = 0; i < arr.size(); i++ ) {
            bool valid = checkAllNums( arr, start, i );
            if ( valid ) {
                start = i+1;
                numChunks += 1;
            }
        }
        return numChunks;
    }
};
