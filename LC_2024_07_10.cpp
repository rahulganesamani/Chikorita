// 1598. Crawler Log Folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for ( auto opn : logs ) {
            if ( opn[0] == '.' ) {
                if ( opn[1] == '.' && count > 0 )
                    count -= 1;
            } else {
                count += 1; 
            }
        }
        return count;
    }
};
