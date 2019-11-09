/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (30.76%)
 * Likes:    894
 * Dislikes: 68
 * Total Accepted:    85.2K
 * Total Submissions: 275K
 * Testcase Example:
 * '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 *
 * Example:
 *
 *
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 *
 * Note:
 *
 *
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 *
 *
 */

// @lc code=start
class NumArray {
   public:
    NumArray(vector<int>& nums) {
        nums1.assign(nums.begin(), nums.end());
        arr.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;

            while (j < arr.size()) {
                arr[j] += nums[i];
                j += low_bit(j);
            }
        }
    }

    void update(int n, int val) {
        int delta = val - nums1[n];
        nums1[n] = val;
        n += 1;

        while (n < arr.size()) {
            arr[n] += delta;
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
    vector<int> nums1;
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
