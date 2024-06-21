// 1052. Grumpy Bookstore Owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int happyCustomer = 0;
        int noGrumpCustomer = 0;
        int maxDiff = 0;
        vector<int> actualCustom;
        vector<int> noGrumpCustom;
        for ( int i = 0; i < customers.size(); i++ ) {
            happyCustomer += customers[i]*(1-grumpy[i]);
            actualCustom.push_back(happyCustomer);
            noGrumpCustomer += customers[i];
            noGrumpCustom.push_back(noGrumpCustomer);
        }

        for ( int i = 0; i < noGrumpCustom.size(); i++ ) {
            int start = i-1;
            int noGrumpCustomStart = 0;
            int actualCustomStart = 0;
            if ( start >= 0 ) {
                noGrumpCustomStart = noGrumpCustom[start];
                actualCustomStart = actualCustom[start];                
            }
            int end = min( int(noGrumpCustom.size() - 1), int( i + minutes - 1) );
            int localMaxDiff = ( ( noGrumpCustom[end] - noGrumpCustomStart ) - ( actualCustom[end] - actualCustomStart ) );
            maxDiff = max( maxDiff, localMaxDiff );
        }
        return (happyCustomer+maxDiff);
    }
};
