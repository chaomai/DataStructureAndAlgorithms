/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (38.67%)
 * Likes:    423
 * Dislikes: 480
 * Total Accepted:    162.6K
 * Total Submissions: 420K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 *
 *
 *
 *
 *
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 *
 *
 *
 *
 *
 * Algorithm of Insertion Sort:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// without dummy node
// class Solution {
//    public:
//     ListNode* insertionSortList(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         // new_head: sorted list
//         // insert pi into new_head
//         ListNode* new_head = nullptr;
//         ListNode* pi = head;

//         while (pi != nullptr) {
//             if (new_head == nullptr) {
//                 new_head = pi;
//                 pi = pi->next;
//                 new_head->next = nullptr;
//             } else {
//                 // insert pi into new_head
//                 ListNode* pj = new_head;
//                 ListNode* pj_prev = nullptr;
//                 while (true) {
//                     if (pj->val > pi->val) {
//                         if (pj_prev != nullptr) {
//                             pj_prev->next = pi;
//                             pi = pi->next;
//                             pj_prev->next->next = pj;
//                         } else {
//                             new_head = pi;
//                             pi = pi->next;
//                             new_head->next = pj;
//                         }
//                         break;
//                     }

//                     pj_prev = pj;
//                     pj = pj->next;

//                     if (pj == nullptr) {
//                         pj_prev->next = pi;
//                         pi = pi->next;
//                         pj_prev->next->next = pj;
//                         break;
//                     }
//                 }
//             }
//         }

//         return new_head;
//     }
// };

// with dummy node
class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // new_head: sorted list
        // insert pi into new_head
        ListNode* dummy_head = new ListNode(INT_MIN);
        dummy_head->next = head;
        ListNode* pi = head->next;
        dummy_head->next->next = nullptr;

        while (pi != nullptr) {
            ListNode* pj = dummy_head->next;
            ListNode* pj_prev = dummy_head;

            while (pj != nullptr) {
                if (pj->val > pi->val) {
                    break;
                }

                pj_prev = pj;
                pj = pj->next;
            }

            pj_prev->next = pi;
            pi = pi->next;
            pj_prev->next->next = pj;
        }

        ListNode* new_head = dummy_head->next;
        delete dummy_head;
        return new_head;
    }
};
// @lc code=end
