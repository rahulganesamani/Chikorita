// 2559. Count Vowel Strings in Ranges

class Solution {
public:
    int vowelEnded( string s ) {
        map<char,int> isVowel;
        isVowel['a'] = 1;
        isVowel['e'] = 1;
        isVowel['i'] = 1;
        isVowel['o'] = 1;
        isVowel['u'] = 1;
        return (isVowel[s[0]] && isVowel[s[s.size() - 1]]);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowelEnd;
        vector<int> answer;
        for ( int i = 0; i < words.size(); i++ ) {
            int isVowelEnded = vowelEnded( words[i] );
            if ( i != 0 ) {
                isVowelEnded += vowelEnd[i-1];
            }
            vowelEnd.push_back( isVowelEnded );
        }
        for ( auto query : queries ) {
            int sol = vowelEnd[ query[1] ];
            if ( query[0] != 0 ) {
                sol -= vowelEnd[ query[0] - 1 ];
            }
            answer.push_back( sol );
        }
        return answer;
    }
};
