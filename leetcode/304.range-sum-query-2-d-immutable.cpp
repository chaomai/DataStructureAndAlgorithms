/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (34.67%)
 * Likes:    609
 * Dislikes: 149
 * Total Accepted:    86.9K
 * Total Submissions: 248.7K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 *
 *
 *
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 *
 * Example:
 *
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 *
 *
 *
 * Note:
 *
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 *
 *
 */

// @lc code=start

// BIT1
// class NumMatrix {
//    public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         arr.resize(matrix.size() + 1);
//         for (int i = 0; i < matrix.size(); i++) {
//             arr[i + 1].resize(matrix[i].size() + 1);
//             for (int j = 0; j < matrix[i].size(); j++) {
//                 int k = j + 1;

//                 while (k < arr[i + 1].size()) {
//                     arr[i + 1][k] += matrix[i][j];
//                     k += k & -k;
//                 }
//             }
//         }
//     }

//     int get(int i, int n) {
//         int sum = 0;
//         while (n > 0) {
//             sum += arr[i][n];
//             n -= n & -n;
//         }
//         return sum;
//     }

//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = 0;
//         for (int i = row1; i <= row2; i++) {
//             sum += get(i + 1, col2 + 1) - get(i + 1, col1);
//         }

//         return sum;
//     }

//    private:
//     vector<vector<int>> arr;
// };

// BIT2
class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        arr.resize(matrix.size() + 1);
        for (int i = 0; i < matrix.size(); i++) {
            arr[i + 1].resize(matrix[i].size() + 1);
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                for (int n = i + 1; n < arr.size(); n += n & -n) {
                    for (int m = j + 1; m < arr[n].size(); m += m & -m) {
                        arr[n][m] += matrix[i][j];
                    }
                }
            }
        }
    }

    int get(int i, int j) {
        int sum = 0;
        for (int n = i; n > 0; n -= n & -n) {
            for (int m = j; m > 0; m -= m & -m) {
                sum += arr[n][m];
            }
        }
        return sum;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return get(row2 + 1, col2 + 1) - get(row2 + 1, col1) -
               get(row1, col2 + 1) + get(row1, col1);
    }

   private:
    vector<vector<int>> arr;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
