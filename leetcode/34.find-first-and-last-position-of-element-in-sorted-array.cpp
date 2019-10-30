/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.41%)
 * Likes:    2152
 * Dislikes: 100
 * Total Accepted:    369.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        if (nums.size() == 0) {
            return ret;
        }

        int first = lower_bound(nums, target);
        if(first == nums.size()){
            return ret;
        } else if (nums[first] != target) {
            return ret;
        } else {
            ret[0] = first;
        }

        int last = upper_bound(nums, target);
        ret[1] = last - 1;

        return ret;
    }

    int lower_bound(vector<int>& nums, int value) {
        int first = 0;
        int last = nums.size();
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] < value) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first;
    }

    int upper_bound(vector<int>& nums, int value) {
        int first = 0;
        int last = nums.size();
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] <= value) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first;
    }
};
// @lc code=end
