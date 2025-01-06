// 1769. Minimum Number of Operations to Move All Balls to Each Box

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> oneIdx;
        for ( int i = 0; i < boxes.size(); i++ ) {
            if ( boxes[i] == '1' )
                oneIdx.push_back(i);
        }
        vector<int> ans;
        for ( int i = 0; i < boxes.size(); i++ ) {
            int count = 0;
            for ( auto ball : oneIdx )
                count += abs( i - ball );
            ans.push_back(count);
        }
        return ans;
    }
};
