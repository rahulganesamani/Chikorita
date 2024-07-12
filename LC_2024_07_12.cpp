// 1717. Maximum Score From Removing Substrings

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int value = 0;
        stack<char> myStack;
        for ( int i = 0; i < s.size(); i++) {
            char c = s[i];
            if ( x > y ) {
                if ( myStack.size() > 0 && myStack.top() == 'a' && c == 'b' ) {
                    myStack.pop();
                    value += x;
                } else {
                    myStack.push(c);
                }
            } else {
                if ( myStack.size() > 0 && myStack.top() == 'b' && c == 'a' ) {
                    myStack.pop();
                    value += y;
                } else {
                    myStack.push(c);
                }
            }
        }
        string newS = "";
        while ( myStack.size() ) {
            newS += myStack.top();
            myStack.pop();
        }
        reverse(newS.begin(), newS.end());
        stack<char> myStackNext;
        for ( int i = 0; i < newS.size(); i++) {
            char c = newS[i];
            if ( x < y ) {
                if ( myStackNext.size() > 0 && myStackNext.top() == 'a' && c == 'b' ) {
                    myStackNext.pop();
                    value += x;
                } else {
                    myStackNext.push(c);
                }
            } else {
                if ( myStackNext.size() > 0 && myStackNext.top() == 'b' && c == 'a' ) {
                    myStackNext.pop();
                    value += y;
                } else {
                    myStackNext.push(c);
                }
            }
        }
        return value;
    }
};
