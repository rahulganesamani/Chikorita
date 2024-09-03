// 1945. Sum of Digits of String After Convert

class Solution {
public:
    int getLucky(string s, int k) {
        string value = "";
        int result;
        for ( char c : s ) {
            value += to_string( c - 'a' + 1 );
        }
        for ( int j = 0; j < k; j++ ) {
            int newVal = 0;
            for ( int i = 0; i < value.size(); i++ ) {
                newVal += (value[i] - '0' );
            }
            value = to_string(newVal);
            result = newVal;
        }
        return result;
    }
};
