/*
9. Palindrome Number
Easy
10.2K
2.5K
Companies
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> numbers;
        if ( x < 0 ) {
            return false;
        }
        else if ( x == 0 ) {
            return true;
        }
        int q = x;
        int r = 0;
        while ( q != 0 ) {
            r = q%10;
            q = q/10;
            numbers.push_back(r);
        }
        int result = 0;
        for ( int i = 0; i < numbers.size()/2; i++ ) {
            if ( numbers[i] != numbers[ numbers.size() - 1 - i ] ) {
                return false;
            }
        }
        return true;
    }
};
