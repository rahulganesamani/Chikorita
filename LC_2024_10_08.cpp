// 1963. Minimum Number of Swaps to Make the String Balanced

class Solution {
public:
    int minSwaps(string s) {
        int result = 0;
        for ( auto c : s ) {
            if ( c == '[' ) {
                result += 1;
            } else if ( result > 0 ) {
                result -= 1;
            }
        }
        return (result+1)/2;
    }
};
