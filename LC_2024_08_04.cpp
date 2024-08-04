// 1508. Range Sum of Sorted Subarray Sums

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long> subArr;
        for ( int i = 0; i < nums.size(); i++ ) {
            long tempSum = nums[i];
            subArr.push_back(tempSum);
            for ( int j = i+1; j < nums.size(); j++ ) {
                tempSum += long(nums[j]);
                subArr.push_back(tempSum);
            }
        }
        sort(subArr.begin(), subArr.end());
        long sum = 0;
        for ( int i = left-1; i < right; i++ )
            sum += subArr[i];
        return (sum % (1000000007));
    }
};
