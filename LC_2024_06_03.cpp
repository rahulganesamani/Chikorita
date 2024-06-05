// 2486. Append Characters to String to Make Subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int lastPosition = 0;
        int notFoundChar = t.size();
        for ( int i = 0; i < t.size(); i++ ) {
            for ( int j = lastPosition; j < s.size(); j++ ) {
                if ( t[i] == s[j] ) {
                    lastPosition = j;
                    notFoundChar--;
                    break;
                }
            }
            if ( t[i] != s[lastPosition++] ) {
                break;
            }
        }
        return notFoundChar;
    }
};
