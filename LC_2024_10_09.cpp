// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int closeCount = 0;
        int result = 0;
        for ( auto c : s ) {
            if ( c == '(' ) {
                openCount += 1;
            }
            else if ( openCount <= closeCount ) {
                    result += 1;
            } else {
                    closeCount += 1;
            }
        }
        return ( abs( openCount - closeCount ) + result );
    }
};
