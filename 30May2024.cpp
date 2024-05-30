// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        for ( int i = 0; i < n; i++ ) {
            int xorLhs = arr[i];
            for ( int j = i + 1; j < n; j++ ) {
                xorLhs ^= arr[j];
                if ( xorLhs == 0 ) {
                    count += (j - i);
                }
            }
        }
        return count;
    }
};
