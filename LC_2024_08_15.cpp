// 860. Lemonade Change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> billCount;
        for ( int i = 0; i < bills.size(); i++ ) {
            if ( bills[i] == 5 ) {
                billCount[5]++;
            } else if ( bills[i] == 10 ) {
                if ( billCount[5] ) {
                    billCount[5]--;
                    billCount[10]++;
                } else {
                    return false;
                }
            } else {
                if ( billCount[10] && billCount[5] ) {
                    billCount[5]--;
                    billCount[10]--;
                    billCount[20]++;
                } else if ( billCount[5] >= 3 ) {
                    billCount[5] -= 3;
                    billCount[20]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
