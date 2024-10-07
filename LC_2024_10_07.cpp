// 2696. Minimum String Length After Removing Substrings

class Solution {
public:
    string stringRemove(string s1, string s2 ) {
        size_t found = s1.find(s2);
        string newS = "";
        for ( int i = 0; i < s1.size(); i++ ) {
            if ( i < found || i >= (found+s2.size()) )
                newS += s1[i];
        }
        return newS;
    }
    bool stringContains(string s1, string s2 ) {
        size_t found = s1.find(s2);
        return ( found != string::npos );
    }
    int minLength(string s) {
        while ( stringContains(s , "AB") || stringContains(s , "CD") ) {
            if (stringContains(s , "AB")) {
                s = stringRemove(s, "AB");
            } else {
                s = stringRemove(s, "CD");
            }
        }
        return s.size();
    }
};
