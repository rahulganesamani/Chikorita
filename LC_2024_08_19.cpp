// 650. 2 Keys Keyboard

class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        if ( n == 1 )
            return count;
        count++;
        int copyNum = 1;
        int totalA = 1;
        while ( totalA < n ) {
            totalA += copyNum;
            int remainA = ( n - totalA );
            if ( (remainA) && (remainA % totalA == 0) ) {
                copyNum = totalA;
                count++;
            }
            count++;
        }
        return count;
    }
};
