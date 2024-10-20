// 1106. Parsing A Boolean Expression

class Solution {
public:
    char boolFunc( char func, stack<char> args ) {
        bool result = (args.top() == 't' );
        args.pop();
        if ( func == '|' ) {
            while ( !args.empty() ) {
                result |= (args.top() == 't' );
                args.pop();
            }
        } else if ( func == '&' ) {
            while ( !args.empty() ) {
                result &= (args.top() == 't' );
                args.pop();
            }
        } else {
            result = !result;
        }
        if ( result ) {
            return 't';
        }
        return 'f';
    }
    bool parseBoolExpr(string expression) {
        stack<char> exprStack;
        char function;
        for ( auto c : expression ) {
            if ( c != ')' ) {
                exprStack.push(c);
            } else {
                stack<char> argStack;
                while ( exprStack.top() != '(' ) {
                    if ( exprStack.top() != ',' )
                        argStack.push(exprStack.top());
                    exprStack.pop();
                }
                exprStack.pop();
                function = exprStack.top();
                exprStack.pop();
                exprStack.push(boolFunc( function, argStack ));
            }
        }
        return ( exprStack.top() == 't' );
    }
};
