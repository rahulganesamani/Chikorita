// 846. Hand of Straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ( hand.size() % groupSize != 0 ) {
            return false;
        }
        map<int,int> numCount;
        for ( auto i : hand ) {
            numCount[ i ] ++;
        }

        auto it = numCount.begin();
        while ( it != numCount.end() ) {
            if ( it->second > 0 ) {
                for ( int i = 0; i < groupSize; i++ ) {
                    if ( numCount.find( it->first + i ) == numCount.end() || numCount[it->first + i] == 0 ) {
                        return false;
                    }
                    numCount[it->first+i]--;
                }
            }
            else
                it++;
        }
        return true;
    }
};
