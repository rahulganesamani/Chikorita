// 3016. Minimum Number of Pushes to Type Word II

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};
class Solution {
public:
    int minimumPushes(string word) {

        map<char, int> charCount;
        for ( auto c : word ) {
            charCount[c]++;
        }

        vector<pair<char, int> > mapcopy(charCount.begin(), charCount.end());
        sort(mapcopy.begin(), mapcopy.end(), less_second<char, int>());

        int finalCount = 0;
        int count = 0;
        for ( int i = 0; i < mapcopy.size(); i++ ) {
            count++;
            if ( count < 9 ) {
                finalCount += mapcopy[i].second;
            } else if ( count < 17 ) {
                finalCount += 2*(mapcopy[i].second);
            } else if  ( count < 25 ) {
                finalCount += 3*(mapcopy[i].second);
            } else {
                finalCount += 4*(mapcopy[i].second);
            }
        }

        return finalCount;
    }
};
