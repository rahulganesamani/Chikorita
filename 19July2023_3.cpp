/*
67. Add Binary
Easy
8.3K
827
Companies
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int a_val, b_val, sum;
        int carry = 0;
        string result = "";
        while ( a.size() != 0 | b.size() != 0 ) {
            if ( a.size() == 0 ) {
                a_val = 0;
                b_val = b.back() - '0';
                b.pop_back();
            }
            else if ( b.size() == 0 ) {
                a_val = a.back() - '0';
                b_val = 0;
                a.pop_back();
            }
            else {
                a_val = a.back() - '0';
                b_val = b.back() - '0';
                a.pop_back();
                b.pop_back();
            }
            sum = a_val + b_val + carry;
            if ( sum == 0 ) {
                result.insert( result.begin(), '0' );
                carry = 0;
            }
            else if ( sum == 1 ) {
                result.insert( result.begin(), '1' );
                carry = 0;
            }
            else if ( sum == 2 ) {
                result.insert( result.begin(), '0' );
                carry = 1;
            }
            else {
                result.insert( result.begin(), '1' );
                carry = 1;
            }
        }
        if ( carry == 1) {
            result.insert( result.begin(), '1' );
        }
        return result;
    }
};
