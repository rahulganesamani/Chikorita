// 2418. Sort the People

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> heighNameMap;
        vector<string> sortNames;
        for ( int i = 0; i < names.size(); i++ )
            heighNameMap[heights[i]] = names[i];
        for ( auto it = heighNameMap.begin(); it != heighNameMap.end(); it++ )
            sortNames.push_back(it->second);
        reverse(sortNames.begin(), sortNames.end());
        return sortNames;
    }
};
