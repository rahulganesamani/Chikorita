// 632. Smallest Range Covering Elements from K Lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> allNums;
        vector<int> groups;
        vector<int> sortAllNums;
        vector<int> sortGroups;
        for ( int i = 0; i < nums.size(); i++ ) {
            for ( auto num : nums[i] ) {
                allNums.push_back(num);
                groups.push_back(i);
            }
        }
        vector<int> indices(allNums.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&]( int a, int b ) -> bool {
                return (allNums[a] < allNums[b]);
             });
        for ( int i = 0; i < indices.size(); i++ ) {
            sortAllNums.push_back(allNums[indices[i]]);
            sortGroups.push_back(groups[indices[i]]);
        }
        map<int,int> groupCount;
        int minWindowSize = nums.size();
        int windowStart = 0;
        int windowEnd = 0;
        int result = -1;
        vector<int> resultArr = {-1,-1};
        while ( windowEnd < sortAllNums.size() ) {
            groupCount[sortGroups[windowEnd]]++;
            while ( groupCount.size() == minWindowSize ) {
                int intervalSize = sortAllNums[windowEnd] - sortAllNums[windowStart];
                if ( ( result == -1 ) || ( result > intervalSize ) || ( ( result ==  intervalSize ) && sortAllNums[windowStart] < resultArr[0] ) ) {
                    result = intervalSize;
                    resultArr[0] = sortAllNums[windowStart];
                    resultArr[1] = sortAllNums[windowEnd];
                }
                groupCount[sortGroups[windowStart]]--;
                if ( groupCount[sortGroups[windowStart]] == 0 ) {
                    groupCount.erase(sortGroups[windowStart]);
                }
                windowStart++;
            }
            windowEnd++;
        }
        return resultArr;
    }
};
