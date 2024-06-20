// 1552. Magnetic Force Between Two Balls

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int minMaxDis = 0;
        int start = 1;
        int end = position[position.size()-1] - position[0];
        while ( start <= end ) {
            int mid = start + (end-start)/2;
            int lastPos = position[0];
            int ballsPlaced = 1;
            for ( int i = 1; i < position.size(); i++ ) {
                if ( position[i] - lastPos >= mid ) {
                    ballsPlaced++;
                    lastPos = position[i];
                }
            }
            if ( ballsPlaced >= m ) {
                minMaxDis = mid;
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return minMaxDis;
    }
};
