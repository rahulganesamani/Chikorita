// 2381. Shifting Letters II

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftCount(s.size(), 0 );
        for ( auto shift : shifts ) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            if ( dir == 1 ) {
                shiftCount[start] += 1;
                if ( end != shiftCount.size() - 1 )
                    shiftCount[end+1] -= 1;
            } else {
                shiftCount[start] -= 1;
                if ( end != shiftCount.size() - 1 )
                    shiftCount[end+1] += 1; 
            }
        }
        int carry = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            shiftCount[i] += carry;
            carry = shiftCount[i];
            int shift = (shiftCount[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};
