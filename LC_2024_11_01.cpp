// 1957. Delete Characters to Make Fancy String

class Solution {
public:
    string makeFancyString(string s) {
        if ( s.size() < 3 )
            return s;
        string fancyString = s.substr(0,2);
        char char1 = fancyString[0];
        char char2 = fancyString[1];
        for ( int i = 2; i < s.size(); i++ ) {
            if ( char1 != char2 || char2 != s[i] ) {
                fancyString += s[i];
                char1 = char2;
                char2 = s[i];       
            }
        }
        return fancyString;
    }
};
