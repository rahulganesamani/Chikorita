// 476. Number Complement

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int count = 0;
        while ( num ) {
            if ( num%2 == 0 )
                res += pow(2, count);
            count++;
            num = num/2;
        }
        return res;
    }
};
