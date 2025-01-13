// 3223. Minimum Length of String After Operations

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> charCount;
        int sum = 0;
        for ( auto c : s ) {
            charCount[c]++;
            sum++;
            if ( charCount[c] > 2 ) {
                charCount[c] -= 2;
                sum -= 2;
            }
        }
        return sum;
    }
};
