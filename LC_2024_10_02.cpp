// 1331. Rank Transform of an Array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ranks;
        map<int,int> rankMap;
        for ( int i : arr ) {
            rankMap[i] = 1;
        }
        int tempRank = 1;
        for ( auto it = rankMap.begin(); it != rankMap.end(); it++ ) {
            rankMap[it->first] = tempRank;
            tempRank++;
        }
        for ( int i : arr ) {
            ranks.push_back(rankMap[i]);
        }
        return ranks;
    }
};
