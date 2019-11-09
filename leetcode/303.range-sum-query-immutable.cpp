/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (40.31%)
 * Likes:    585
 * Dislikes: 874
 * Total Accepted:    162.3K
 * Total Submissions: 400.3K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * Example:
 *
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 *
 *
 *
 * Note:
 *
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 *
 */

// @lc code=start
class NumArray {
   public:
    NumArray(vector<int>& nums) {
        arr.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            update(i + 1, nums[i]);
        }
    }

    void update(int n, int val) {
        while (n < arr.size()) {
            arr[n] += val;
            n += low_bit(n);
        }
    }

    int get(int n) {
        int ans = 0;
        while (n > 0) {
            ans += arr[n];
            n -= low_bit(n);
        }

        return ans;
    }

    int low_bit(int x) { return x & -x; }

    int sumRange(int i, int j) { return get(j + 1) - get(i); }

   private:
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
