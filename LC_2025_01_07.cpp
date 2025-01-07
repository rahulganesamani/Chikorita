// 1408. String Matching in an Array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for ( int i = 0; i < words.size(); i++ ) {
            bool found = false;
            int j = 0;
            while ( j < words.size() && found == 0 ) {
                if ( i != j && words[j].find(words[i]) != string::npos ) {
                    result.push_back(words[i]);
                    found = true;
                }
                j++;
            }
        }
        return result;
    }
};
