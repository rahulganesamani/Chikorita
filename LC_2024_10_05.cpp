// 567. Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if ( s2.size() < s1.size() )
            return false;
        map<char, int> s1Map;
        for ( auto c1 : s1 ) {
            s1Map[c1]++;
        }
        for ( int i = 0; i <= (s2.size()-s1.size()); i++ ) {
            map<char, int> s2Map;
            for ( int j = 0; j < s1.size(); j++ ) {
                s2Map[ s2[i+j] ]++;
            }
            bool found = true;
            for ( auto it = s1Map.begin(); it != s1Map.end(); it++ ) {
                if ( s1Map[it->first] != s2Map[it->first] ) {
                    found = false;
                    break;
                }
            }
            if ( found )
                return found;
        }
        return false;
    }
};
