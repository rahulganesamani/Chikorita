// 648. Replace Words

class Solution {
public:
    string findWord(vector<string>& dictionary, string sentence) {
        unordered_set<string> dictKeys(dictionary.begin(), dictionary.end());
        string newWord = "";
        for ( auto alpha : sentence ) {
            newWord += string( 1, alpha );
            if ( dictKeys.find( newWord ) != dictKeys.end() ) {
                return newWord;
            }
        }
        return newWord;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string newSentence = "";
        string newWord = "";
        for ( auto alpha : sentence ) {
            if ( string(1, alpha) == " " ) {
                newSentence += findWord(dictionary, newWord);
                newSentence += " ";
                newWord = "";
            }
            else {
                newWord += string(1, alpha);
            }
        }
        newSentence += findWord(dictionary, newWord);
        return newSentence;
    }
};
