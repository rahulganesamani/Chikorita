// 2270. Number of Ways to Split Array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> prefixNums;
        long carry = 0;
        int count = 0;
        long thresh;
        int n = nums.size();
        for ( int i = 0; i < n; i++ ) {
            prefixNums.push_back( nums[i] + carry );
            carry = prefixNums[i];
        }
        thresh = prefixNums[ n - 1 ];
        if ( thresh % 2 == 1 )
            thresh++;
        for ( int i = 0; i < n - 1; i++ ) {
            if ( prefixNums[i] >= thresh/2 )
                count++;
        }
        return count;
    }  
};
