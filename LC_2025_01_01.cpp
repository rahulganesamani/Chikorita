// 1422. Maximum Score After Splitting a String

class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int totalZero = 0;
        int totalOne = 0;
        for ( auto i : s ) {
            if ( i == '1' ) {
                totalOne += 1;
            }
        }
        for ( int i = 0; i < s.size() - 1; i++ ) {
            if ( s[i] == '0' ) {
                totalZero += 1;
            } else {
                totalOne -= 1;
            }
            maxScore = max( ( totalZero + totalOne ), maxScore );
        }
        return maxScore;
    }
};
