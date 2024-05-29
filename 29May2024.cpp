// 1404. Number of Steps to Reduce a Number in Binary Representation to One

class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        int carry = 0;
        for ( int i = s.size() - 1; i > 0; i-- ) {
            if ( s[i] == '0' && carry == 0 ) {
                count += 1;
            }
            else if ( s[i] == '0' && carry == 1 ) {
                count += 2;
                carry = 1;
            }
            else if ( s[i] == '1' && carry == 0 ) {
                count += 2;
                carry = 1;
            }
            else {
                count += 1;
                carry = 1;
            }
        }
        return ( count + carry );
    }
};
