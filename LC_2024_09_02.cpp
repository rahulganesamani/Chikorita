// 1894. Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sumChalks = 0;
        for ( int i : chalk ) {
            sumChalks += i;
        }
        long long lastChalks = k % sumChalks;
        for ( int i = 0; i < chalk.size(); i++ ) {
            if ( lastChalks < chalk[i] ) {
                return i;
            }
            lastChalks -= chalk[i];
        }
        return 0;
    }
};
