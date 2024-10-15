// Separate Black and White Balls

class Solution {
public:
    long long minimumSteps(string s) {
        long long result = 0;
        long long numWhiteBall = 0;
        for ( auto i : s ) {
            if ( i == '1' ) {
                numWhiteBall += 1;
            } else {
                result += numWhiteBall;
            }
        }
        return result;
    }
};
