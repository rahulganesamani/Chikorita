// 1122. Relative Sort Array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> arr1Count;
        vector<int> finalArr;
        for ( auto i : arr1 ) {
            arr1Count[i]++;
        }
        for ( auto i : arr2 ) {
            while ( arr1Count[i] ) {
                finalArr.push_back(i);
                arr1Count[i]--;
            }
        }
        for ( auto i = arr1Count.begin(); i != arr1Count.end(); i++ ) {
            while ( i->second ) {
                finalArr.push_back(i->first);
                (i->second)--;
            }
        }
        return finalArr;
    }
};
