// 1823. Find the Winner of the Circular Game

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for ( int i = 1; i <= n; i++ ) {
            q.push(i);
        }
        while ( q.size() >= 2 ) {
            for ( int i = 0; i < k-1; i++ ) {
                int ele = q.front();
                q.pop();
                q.push(ele);
            }
            q.pop();
        }
        return q.front();
    }
};
