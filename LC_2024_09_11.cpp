// 2220. Minimum Bit Flips to Convert Number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        while ( start > 0 && goal > 0 ) {
            if ( start%2 != goal%2 )
                count++;
            start = start/2;
            goal = goal/2;
        }
        while ( goal ) {
            if ( goal%2 )
                count++;
            goal = goal/2;
        }
        while ( start ) {
            if ( start%2 )
                count++;
            start = start/2;
        }
        return count;
    }
};
