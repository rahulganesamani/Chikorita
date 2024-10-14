// Maximal Score After Applying K Operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long score = 0;
        priority_queue<int> kMaxPq;
        for ( auto i : nums ) {
            kMaxPq.push( i );
        }
        while ( k ) {
            int val = kMaxPq.top();
            kMaxPq.pop();
            score += val;
            kMaxPq.push(ceil(double(val)/double(3)));
            k--;
        }
        return score;
    }
};
