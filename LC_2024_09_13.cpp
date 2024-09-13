// 1310. XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixArr(arr.size());
        prefixArr[0] = arr[0];
        for ( int i = 1; i < arr.size(); i++ )
            prefixArr[i] = prefixArr[i-1]^arr[i];
        vector<int> answer;
        for ( int i = 0 ; i < queries.size(); i++ ) {
            if ( queries[i][0] == 0 )
                answer.push_back(prefixArr[queries[i][1]]);
            else
                answer.push_back(prefixArr[queries[i][1]] ^ prefixArr[queries[i][0]-1] );
        }
        return answer;
    }
};
