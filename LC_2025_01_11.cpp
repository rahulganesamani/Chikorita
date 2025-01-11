// 1400. Construct K Palindrome Strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        if ( s.size() < k )
            return false;
        map<char,int> charCount;
        int numOddChar = 0;
        for ( auto c : s )
            charCount[c]++;
        for ( auto it = charCount.begin(); it != charCount.end(); it++ ) {
            if ( it->second % 2 != 0 )
                numOddChar++;
        }
        return ( numOddChar <= k );
    }
};
