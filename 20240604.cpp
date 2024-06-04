// 409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> charCount;
        int individual = 0;
        int pair = 0;

        for ( int i = 0; i < s.size(); i++ ) {
            if ( charCount.find(s[i]) == charCount.end() ) {
                charCount[s[i]] = 0;
            }
            charCount[s[i]]+=1;
        }

        for ( auto i = charCount.begin(); i != charCount.end(); i++ ) {
            if ( i->second > 1 ) {
                if ( i->second % 2 == 0 ) {
                    pair += (i->second);
                }
                else {
                    pair += (i->second-1);
                    individual = 1;
                }
            }
            else if ( individual == 0 ) {
                individual = 1;
            }
        }
        return ( pair + individual );
    }
};
