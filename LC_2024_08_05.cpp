// 2053. Kth Distinct String in an Array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> stringCount;
        for ( auto s : arr ) {
            stringCount[s]++; 
        }
        int count = 0;
        int idx  = 0;
        while ( idx < arr.size() ) {
            if ( stringCount[arr[idx]] == 1 ) {
                count++;
                if ( count == k )
                    return arr[idx];
            }
            idx++;
        }
        return "";
    }
};
