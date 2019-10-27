/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.96%)
 * Likes:    2675
 * Dislikes: 211
 * Total Accepted:    429.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 *
 */

// @lc code=start

// error method 1
// class Solution {
//    public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ret;
//         for (int i = 0; i < intervals.size(); i++) {
//             int j = 0;
//             for (; j < ret.size(); j++) {
//                 if ((ret[j][0] <= intervals[i][0] &&
//                     ret[j][1] >= intervals[i][0]) ||
//                     (intervals[i][0] <= ret[j][0] &&
//                     intervals[i][1] >= ret[j][0])) {
//                     ret[j][0] = std::min(intervals[i][0], ret[j][0]);
//                     ret[j][1] = std::max(intervals[i][1], ret[j][1]);
//                     break;
//                 }
//             }

//             if (j >= ret.size()) {
//                 ret.push_back(intervals[i]);
//             }
//         }

//         return ret;
//     }
// };

// sort
// class Solution {
//    public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ret;

//         if (intervals.size() == 0) {
//             return ret;
//         }

//         sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int> &b) {return a[0] < b[0];});
//         ret.push_back(intervals[0]);
//         for (int i = 1; i < intervals.size(); i++) {
//             int j = ret.size() - 1;
//             if (intervals[i][0] <= ret[j][1]) {
//                 ret[j][1] = max(intervals[i][1], ret[j][1]);
//             } else {
//                 ret.push_back(intervals[i]);
//             }
//         }

//         return ret;
//     }
// };

// interval tree
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    }
};
// @lc code=end
