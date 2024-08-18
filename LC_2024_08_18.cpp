// 264. Ugly Number II

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> twoArray;
        vector<int> threeArray;
        vector<int> fiveArray;
        twoArray.push_back(1);
        threeArray.push_back(1);
        fiveArray.push_back(1);
        int twoIdx = 0;
        int threeIdx = 0;
        int fiveIdx = 0;
        if (n == 1){
            return 1;
        }
        for ( int i = 1; i < n; i++ ) {
            int val = 0;
            int twoVal = twoArray[twoIdx] * 2;
            int threeVal = threeArray[threeIdx] * 3;
            int fiveVal = fiveArray[fiveIdx] * 5;
            if ( twoVal <= threeVal && twoVal <= fiveVal ) {
                val = twoVal;
            } else if ( threeVal <= twoVal && threeVal <= fiveVal ) {
                val = threeVal;
            } else {
                val = fiveVal;
            }
            if ( twoVal == val )
                twoIdx++;
            if ( threeVal == val )
                threeIdx++;
            if ( fiveVal == val )
                fiveIdx++;
            twoArray.push_back(val);
            threeArray.push_back(val);
            fiveArray.push_back(val);
        }
        return twoArray[n-1];      
    }
};
