// 2914. Minimum Number of Changes to Make Binary String Beautiful

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            if ( s[i] != s[i+1] )
                count++;
            i++;
        }
        return count;
    }
};
