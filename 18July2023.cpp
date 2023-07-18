/*
20. Valid Parentheses
Easy
20.9K
1.3K
Companies
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/

class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        for ( int i = 0; i < s.size(); i++ ) {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
                stack.push_back(s[i]);
            }
            else {
                if ( s[i] == ')' ) {
                    if ( stack.back() == '(' ) {
                        stack.pop_back();
                    }
                    else {
                        return false;
                    }
                }
                else if ( s[i] == ']' ) {
                    if ( stack.back() == '[' ) {
                        stack.pop_back();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if ( stack.back() == '{' ) {
                        stack.pop_back();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if ( stack.size() > 0 ) {
            return false;
        }
        return true;
    }
};
