/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    2517
 * Dislikes: 197
 * Total Accepted:    456.1K
 * Total Submissions: 904.4K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */

// @lc code=start

// bubble sort
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = 1; j < nums.size() - i; j++) {
//                 if (nums[j - 1] > nums[j]) {
//                     swap(nums[j - 1], nums[j]);
//                 }
//             }
//         }
//         return nums[nums.size() - k];
//     }
// };

// selection sort
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for (int i = 0; i < nums.size(); i++) {
//             int min_idx = i;
//             int min = INT_MAX;
//             for (int j = i; j < nums.size(); j++) {
//                 if (nums[j] < min) {
//                     min_idx = j;
//                     min = nums[j];
//                 }
//             }
//             swap(nums[i], nums[min_idx]);
//         }
//         return nums[nums.size() - k];
//     }
// };

// insertion sort
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i; j > 0; j--) {
//                 if (nums[j - 1] > nums[j]) {
//                     swap(nums[j - 1], nums[j]);
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return nums[nums.size() - k];
//     }
// };

// shell sort
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for (int h = nums.size(); h > 0; h >>= 1) {
//             for (int i = h; i < nums.size(); i++) {
//                 for (int j = i; j > 0 && j - h >= 0; j -= h) {
//                     if (nums[j - h] > nums[j]) {
//                         swap(nums[j - h], nums[j]);
//                     } else {
//                         break;
//                     }
//                 }
//             }
//         }
//         return nums[nums.size() - k];
//     }
// };

// merge sort
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         vector<int> tmp(nums.size());
//         merge_sort(nums, tmp, 0, nums.size());
//         return nums[nums.size() - k];
//     }

//     // merge sort [b, e)
//     void merge_sort(vector<int>& nums, vector<int>& tmp, int b, int e) {
//         // [b, e)是待排序数组，如果e - b <=
//         1，那么区间内将没有元素或只有一个元素，因此直接返回 if (e - b <= 1) {
//             return;
//         }

//         int mid = b + (e - b) / 2;
//         merge_sort(nums, tmp, b, mid);
//         merge_sort(nums, tmp, mid, e);

//         for (int i = b; i < e; i++) {
//             tmp[i] = nums[i];
//         }

//         int i = b;
//         int b1 = b;
//         int b2 = mid;
//         while (b1 < mid && b2 < e) {
//             if (tmp[b1] < tmp[b2]) {
//                 nums[i] = tmp[b1];
//                 b1++;
//             } else {
//                 nums[i] = tmp[b2];
//                 b2++;
//             }
//             i++;
//         }

//         while (b1 < mid) {
//             nums[i] = tmp[b1];
//             b1++;
//             i++;
//         }

//         while (b2 < e) {
//             nums[i] = tmp[b2];
//             b2++;
//             i++;
//         }
//     }
// };

// quick sort1
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         quick_sort(nums, 0, nums.size());
//         return nums[nums.size() - k];
//     }

//     // quick sort [b. e)
//     void quick_sort(vector<int>& nums, int b, int e) {
//         if (b >= e) {
//             return;
//         }

//         // partition [b, e)
//         // b: pivot
//         // [b + 1, m): <= pivot
//         // [m, e): > pivot
//         int pivot = nums[b];
//         int m = b + 1;
//         for (int i = b + 1; i < e; i++) {
//             if (nums[i] <= pivot) {
//                 swap(nums[i], nums[m]);
//                 m++;
//             }
//         }

//         swap(nums[b], nums[m - 1]);

//         // m - 1不再参与接下来的排序
//         quick_sort(nums, b, m - 1);
//         quick_sort(nums, m, e);
//     }
// };

// quick sort2
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         quick_sort(nums, 0, nums.size());
//         return nums[nums.size() - k];
//     }

//     // quick sort [b. e)
//     void quick_sort(vector<int>& nums, int b, int e) {
//         if (b >= e) {
//             return;
//         }

//         // partition [b, e)
//         // b: pivot
//         // [b + 1, i): <= pivot
//         // (j, e): > pivot
//         int pivot = nums[b];
//         int i = b + 1;
//         int j = e - 1;
//         while (true) {
//             while (i < e) {
//                 if (nums[i] > pivot) {
//                     break;
//                 }
//                 i++;
//             }

//             while (j > b) {
//                 if (nums[j] <= pivot) {
//                     break;
//                 }
//                 j--;
//             }

//             if (i >= j) {
//                 break;
//             }

//             swap(nums[i], nums[j]);
//         }

//         swap(nums[b], nums[j]);

//         // j不再参与接下来的排序
//         quick_sort(nums, b, j);
//         quick_sort(nums, j + 1, e);
//     }
// };

// heap sort1
// class Solution {
//    public:
//     int findKthLargest(vector<int>& nums, int k) {
//         heap_sort(nums);
//         return nums[nums.size() - k];
//     }

//     void sink(vector<int>& nums, int k, int n) {
//         for (int i = k; 2 * i + 1 < n;) {
//             int left_child = 2 * i + 1;
//             int right_child = left_child + 1;
//             int max = i;

//             if (nums[max] < nums[left_child]) {
//                 max = left_child;
//             }

//             if (right_child < n && nums[max] < nums[right_child]) {
//                 max = right_child;
//             }

//             if (i != max) {
//                 swap(nums[i], nums[max]);
//                 i = max;
//             } else {
//                 break;
//             }
//         }
//     }

//     void heap_sort(vector<int>& nums) {
//         for (int i = int((nums.size() - 2) / 2); i >= 0; i--) {
//             sink(nums, i, nums.size());
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             sink(nums, 0, nums.size() - i);
//             swap(nums[0], nums[nums.size() - 1 - i]);
//         }
//     }
// };

// heap sort2
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        heap_sort(nums);
        return nums[nums.size() - k];
    }

    void swim(vector<int>& nums, int k) {
        for (int i = k; (i - 1) / 2 >= 0;) {
            int parent = (i - 1) / 2;
            if (nums[parent] < nums[i]) {
                swap(nums[parent], nums[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void sink(vector<int>& nums, int k, int n) {
        for (int i = k; 2 * i + 1 < n;) {
            int left_child = 2 * i + 1;
            int right_child = left_child + 1;
            int max = i;

            if (nums[max] < nums[left_child]) {
                max = left_child;
            }

            if (right_child < n && nums[max] < nums[right_child]) {
                max = right_child;
            }

            if (i != max) {
                swap(nums[i], nums[max]);
                i = max;
            } else {
                break;
            }
        }
    }

    void heap_sort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            swim(nums, i);
        }

        for (int i = 0; i < nums.size(); i++) {
            sink(nums, 0, nums.size() - i);
            swap(nums[0], nums[nums.size() - 1 - i]);
        }
    }
};

// @lc code=end
