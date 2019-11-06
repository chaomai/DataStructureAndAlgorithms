/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (23.84%)
 * Likes:    635
 * Dislikes: 94
 * Total Accepted:    29.5K
 * Total Submissions: 123.3K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 *
 * You need to return the number of important reverse pairs in the given
 * array.
 *
 * Example1:
 *
 * Input: [1,3,2,3,1]
 * Output: 2
 *
 *
 * Example2:
 *
 * Input: [2,4,3,5,1]
 * Output: 3
 *
 *
 * Note:
 *
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 *
 *
 */

// @lc code=start

// merge sort
class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        vector<int> arr(nums.size());
        return merge_sort(nums, arr, 0, nums.size());
    }

    int merge_sort(vector<int>& nums, vector<int>& arr, int b, int e) {
        if (b + 1 >= e) {
            return 0;
        }

        int mid = b + (e - b) / 2;
        int lc = merge_sort(nums, arr, b, mid);
        int rc = merge_sort(nums, arr, mid, e);

        for (int i = b; i < e; i++) {
            arr[i] = nums[i];
        }

        int i = b;
        int j = mid;
        int k = b;
        int count = lc + rc;

        while (i < mid && j < e) {
            while (j < e && arr[i] > 2 * arr[j]) {
                j++;
            }
            i++;
        }

        i = b;
        j = mid;
        while (i < mid && j < e) {
            if (arr[i] < arr[j]) {
                nums[k] = arr[i];
                i++;
            } else {
                nums[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i < mid) {
            nums[k] = arr[i];
            i++;
            k++;
        }

        while (j < e) {
            nums[k] = arr[j];
            j++;
            k++;
        }

        return count;
    }
};
// @lc code=end
