// 1395. Count Number of Teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        map<int, vector<int>> numGreater;
        map<int, vector<int>> numLesser;
        for ( int i = 0; i < rating.size() - 1; i++ ) {
            for ( int j = i+1; j < rating.size(); j++ ) {
                if ( rating[j] > rating[i] ) {
                    numGreater[rating[i]].push_back(rating[j]);
                } else if ( rating[j] < rating[i] ) {
                    numLesser[rating[i]].push_back(rating[j]);
                }
            }
        }
        int totalCount = 0;
        for ( auto it = numGreater.begin(); it != numGreater.end(); it++ ) {
            for ( auto j : it->second ) {
                totalCount += numGreater[j].size();
            }
        }
        for ( auto it = numLesser.begin(); it != numLesser.end(); it++ ) {
            for ( auto j : it->second ) {
                totalCount += numLesser[j].size();
            }
        }
        return totalCount;
    }
};
