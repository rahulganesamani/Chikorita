// 2678. Number of Senior Citizens

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for ( auto citizen : details ) {
            if ( ( citizen[11] > '6' ) || ( citizen[11] == '6' && citizen[12] > '0' ) ) {
                count +=1;
            }
        }
        return count;
    }
};
