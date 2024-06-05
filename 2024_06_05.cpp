// 1002. Find Common Characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> hash1( 26, 0 );
        vector<int> hash2( 26, 0 );
        vector<string> commonString;
        for ( auto ch : words[0] ) {
            hash1[ ch - 'a' ]++;
        }

        for ( auto word : words ) {
            for ( auto ch : word ) {
                hash2[ ch - 'a' ]++;
            }
            for ( int i = 0; i < 26; i++ ) {
                hash1[i] = min( hash1[i], hash2[i] );
                hash2[i] = 0;
            }
        }

        for ( int i = 0; i < 26; i++ ) {
            while ( hash1[i] > 0 ) {
                commonString.push_back( string( 1, ('a' + i) ) );
                hash1[i]--;
            }
        }
        return commonString;
    }
};
