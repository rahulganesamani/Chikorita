// 703. Kth Largest Element in a Stream
class KthLargest {
    int myk = 0;
    vector<int> mynums;
public:
    KthLargest(int k, vector<int>& nums) {
        myk = k;
        sort(nums.begin(), nums.end());
        mynums = nums;
    }
    
    int add(int val) {
        int l = 0;
        int r = mynums.size();
        int mid = 0;
        while ( l < r ) {
            mid = l + ( r - l )/2;
            if ( mynums[mid] < val )
                l = mid + 1;
            else
                r = mid;
        }
        mynums.insert (mynums.begin() + l, val);
        return (mynums[mynums.size()-myk]);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
