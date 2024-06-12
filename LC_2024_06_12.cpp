// 75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> ballCount;
        int j = 0;
        for ( auto i : nums ) {
            ballCount[i]++;
        }
        for ( int i = 0; i < 3; i++ ) {
            while ( ballCount[i] ) {
                nums[j] = i;
                ballCount[i]--;
                j++;
            }
        }
    }
};
