// 1190. Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> myStack;
        queue<char> myQueue;
        string ans = "";
        for ( auto c : s ) {
            if ( c != ')' ) {
                myStack.push(c);
            } else {
                while ( myStack.top() != '(' ) {
                    myQueue.push(myStack.top());
                    myStack.pop();                    
                }
                myStack.pop();
                while ( myQueue.size() > 0 ) {
                    myStack.push(myQueue.front());
                    myQueue.pop();
                }
            }
        }
        while( myStack.size() > 0 ) {
            ans += myStack.top();
            myStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
