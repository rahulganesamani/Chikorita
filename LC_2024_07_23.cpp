// 1636. Sort Array by Increasing Frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> numFreq;
        for ( auto i : nums )
            numFreq[i]++;
    
        map<int,vector<int>> freqNums;
        for ( auto it = numFreq.begin(); it != numFreq.end(); it++ )
            (freqNums[it->second]).push_back(it->first);
    
        vector<int> sortNum;
        for ( auto it = freqNums.begin(); it != freqNums.end(); it++ ) {
            for ( int i = (it->second).size() - 1; i >= 0; i-- ) {
                for ( int j = 0; j < numFreq[(it->second)[i]]; j++ )
                    sortNum.push_back((it->second)[i]);
            }
                
        }
        return sortNum;
    }
};
