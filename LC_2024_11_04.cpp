// 3163. String Compression III

class Solution {
public:
    string compressedString(string word) {
        string result = "";
        int count = 0;
        char c = word[0];
        for ( int i = 0; i < word.size(); i++ ) {
            if ( word[i] != c || count == 9 ) {
                result += to_string(count);
                result += c;     
                c = word[i];
                count = 1;     
            } else {
                count++;
            }
        }
        if ( count > 0 ) {
            result += to_string(count);
            result += c;
        }
        return result;
    }
};
