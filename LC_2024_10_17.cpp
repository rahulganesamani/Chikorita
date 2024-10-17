// 670. Maximum Swap

class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<int> sortNumVector;
        vector<int> numVector;
        int newNum = num;
        while ( newNum ) {
            sortNumVector.push( newNum%10 );
            numVector.push_back( newNum%10 );
            newNum /= 10;
        }
        int replace = -1;
        int replaceWith = -1;
        for ( int i = (numVector.size()-1); i >= 0; i-- ) {
            if ( numVector[i] != sortNumVector.top() ) {
                replace = sortNumVector.top() ;
                replaceWith = numVector[i];
                numVector[i] = sortNumVector.top() ;
                break;
            }
            sortNumVector.pop();
        }
        if ( replace == -1 )
            return num;

        int result = 0;
        for ( int i = 0; i < numVector.size(); i++ ) {
            if ( numVector[i] == replace ) {
                numVector[i] = replaceWith;
                break;
            }
        }
        for ( int i = (numVector.size()-1); i >= 0; i-- ) {
            result *= 10;
            result += numVector[i];
        }
        return result;
    }
};
