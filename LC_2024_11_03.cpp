// 796. Rotate String

class Solution {
public:
    bool rotateString(string s, string goal) {
        if ( s.size() != goal.size() )
            return false;
        queue<char> sQueue;
        queue<char> goalQueue;
        for ( int i = 0; i < s.size(); i++ ) {
            sQueue.push(s[i]);
            goalQueue.push(goal[i]);
        }
        for ( int i = 0; i < s.size(); i++ ) {
            if ( sQueue == goalQueue )
                return true;
            goalQueue.push(goalQueue.front());
            goalQueue.pop();
        }
        return false;
    }
};
