/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (27.92%)
 * Likes:    3971
 * Dislikes: 161
 * Total Accepted:    386.2K
 * Total Submissions: 1.4M
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 *
 * LRUCache cache = new LRUCache( 2 capacity  );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 *
 *
 *
 */

// @lc code=start
class LRUCache {
   private:
    struct Node {
        int key;
        int value;
        shared_ptr<Node> prev;
        shared_ptr<Node> next;

        Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
        Node(int k, int val)
            : key(k), value(val), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, shared_ptr<Node>> m;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size;
    int cap;

   public:
    LRUCache(int capacity) {
        head = make_shared<Node>();
        tail = make_shared<Node>();
        head->next = tail;
        tail->prev = head;
        size = 0;
        cap = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        auto n = m[key];
        // move to front;
        detachNode(n);
        insertFront(n);

        return n->value;
    }

    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            auto n = make_shared<Node>(key, value);
            m[key] = n;

            if (size == cap) {
                removeLruNode();
            } else {
                size++;
            }

            insertFront(n);
        } else {
            auto n = m[key];
            detachNode(n);
            n->value = value;
            insertFront(n);
        }
    }

    void detachNode(shared_ptr<Node> n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insertFront(shared_ptr<Node> n) {
        n->next = head->next;
        n->next->prev = n;
        head->next = n;
        n->prev = head;
    }

    void removeLruNode() {
        if (head->next == tail) {
            return;
        }
        auto n = tail->prev;
        detachNode(n);
        m.erase(n->key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
