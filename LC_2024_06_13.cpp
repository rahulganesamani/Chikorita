// 2037. Minimum Number of Moves to Seat Everyone

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort( seats.begin(), seats.end() );
        sort( students.begin(), students.end() );
        int numMoves = 0;
        for ( int i = 0; i < students.size(); i++ ) {
            int diff = students[i] - seats[i];
            if ( diff < 0 )
                diff *= -1;
            numMoves += diff;
        }
        return numMoves;
    }
};
