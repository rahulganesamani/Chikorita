// 3042. Count Prefix and Suffix Pairs I

class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        bool res = true;
        if ( str1.size() > str2.size() )
            return false;
        int pfxIdx = 0;
        int sfxIdx = str2.size() - str1.size();
        for ( int i = 0; i < str1.size(); i++ ) {
            if ( str1[i] != str2[pfxIdx] || str1[i] != str2[sfxIdx] )
                return false;
            pfxIdx++;
            sfxIdx++;
        }
        return res;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for ( int i = 0; i < n - 1; i++ ) {
            for ( int j = i+1; j < n; j++ ) {
                if ( isPrefixAndSuffix(words[i], words[j]) )
                    count += 1;
            }
        }
        return count;
    }
};
