/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (37.76%)
 * Likes:    1815
 * Dislikes: 95
 * Total Accepted:    213K
 * Total Submissions: 562.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        ListNode* r_b = nullptr;
        ListNode* r_e = nullptr;
        quick_sort(head, &r_b, &r_e);
        return r_b;
    }

    void quick_sort(ListNode* head, ListNode** ret_b, ListNode** ret_e) {
        if (head == nullptr) {
            *ret_b = nullptr;
            *ret_e = nullptr;
            return;
        }

        if (head->next == nullptr) {
            *ret_b = head;
            *ret_e = head;
            return;
        }

        ListNode* pivot = head;
        ListNode* pi = pivot->next;
        // <= pivot
        ListNode* dummy_head1 = new ListNode(INT_MIN);
        ListNode* di = dummy_head1;
        // > pivot
        ListNode* dummy_head2 = new ListNode(INT_MIN);
        ListNode* dj = dummy_head2;

        while (pi != nullptr) {
            if (pi->val <= pivot->val) {
                di->next = pi;
                di = di->next;
            } else {
                dj->next = pi;
                dj = dj->next;
            }
            pi = pi->next;
        }

        di->next = nullptr;
        dj->next = nullptr;
        di = dummy_head1->next;
        dj = dummy_head2->next;
        delete dummy_head1;
        delete dummy_head2;

        ListNode* ri_b = nullptr;
        ListNode* ri_e = nullptr;
        ListNode* rj_b = nullptr;
        ListNode* rj_e = nullptr;
        quick_sort(di, &ri_b, &ri_e);
        quick_sort(dj, &rj_b, &rj_e);

        // ri_e -> pivot -> rj_b
        if (ri_b != nullptr) {
            *ret_b = ri_b;
            ri_e->next = pivot;
            pivot->next = rj_b;
        } else {
            *ret_b = pivot;
            pivot->next = rj_b;
        }

        if (rj_b != nullptr) {
            *ret_e = rj_e;
        } else {
            *ret_e = pivot;
        }
    }
};
// @lc code=end
