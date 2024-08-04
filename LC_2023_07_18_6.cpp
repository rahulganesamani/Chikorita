/*
35. Search Insert Position
Easy
13.9K
606
Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int stop) {
        if ( stop == start + 1 ) {
            return stop;
        }
        int pivot = ( start + stop ) / 2;
        if ( nums[pivot] < target ) {
            return binarySearch( nums, target, pivot, stop);
        }
        else {
            return binarySearch( nums, target, start, pivot);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        if ( nums[0] >= target ) {
            return 0;
        }

        if ( nums.back() < target ) {
            return nums.size();
        }

        if (nums.size() == 1) {
            if ( target > nums[0] ) {
                return 1;
            }
            else {
                return 0;
            }
        }

        return binarySearch( nums, target, 0, nums.size()-1 );
    }
};
