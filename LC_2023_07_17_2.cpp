/*
14. Longest Common Prefix
Easy
14.8K
4.1K
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str1 = strs[0];
        string result = "";
        string substr = "";
        int count;
        if ( strs.size() == 1 ) {
            return str1;
        }
        for ( int i = 0; i < str1.size(); i++ ) {
            substr += str1[i];
            count = 1;
            for ( int j = 1; j < strs.size(); j++) {
                if ( strs[j].find(substr) == 0 ) {
                    count += 1;
                }
            }
            if( count != strs.size() ) {
                return result;
            }
            result = substr;
        }
        return result;
    }
};
