// 633. Sum of Square Numbers
class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0;
        while ( i <= sqrt(c) ) {
            double isq = sqrt(c-i*i);
            if ( isq == (int)isq ) 
                return true;
            i++;
        }
        return false;
    }
};
