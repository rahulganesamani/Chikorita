// 3110. Score of a String

class Solution {
public:
    int scoreOfString(string s) {
        int finalDiff = 0;
        for ( int i = 0; i < s.size() - 1; i++ ) {
            finalDiff += abs(s[i] - s[i+1]);
        }
        return finalDiff;
    }
};
