// 2134. Minimum Swaps to Group All 1's Together II

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        vector<int> numSum;
        for ( auto i : nums ) {
            totalOnes += i;
            numSum.push_back(totalOnes);
        }
        int minSwap = -1;
        for ( int i = 0; i < nums.size(); i++ ) {
            int start = i;
            int tempSum = 0;
            int stop = ( start + totalOnes - 1 ) % nums.size();
            if ( stop > start )
                tempSum = numSum[stop] - numSum[start] + nums[start];
            else if ( stop < start )
                tempSum = totalOnes - numSum[start-1] + numSum[stop];
            else
                tempSum = totalOnes;
            if ( minSwap == -1 || (totalOnes-tempSum) < minSwap  )
                minSwap = (totalOnes-tempSum);
        }
        return minSwap;
    }
};
