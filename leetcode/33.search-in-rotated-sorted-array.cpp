/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.27%)
 * Likes:    3140
 * Dislikes: 371
 * Total Accepted:    505.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int first = 0;
        int last = nums.size();
        while (first < last) {
            int mid = first + (last - first) / 2;
            bool is_in_left = true;
            if (mid > 0) {
                if (nums[0] < nums[mid]) {
                    // mid | rotation point
                    is_in_left = true;
                } else {
                    // rotation point | mid
                    is_in_left = false;
                }
            }

            if (nums[mid] > target) {
            }
        }
        return -1;
    }
};
// @lc code=end
