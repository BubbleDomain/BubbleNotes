#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/10
 * @description: 142.linked-list-cycle-ii
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 哈希表解法
ListNode *detectCycle1(ListNode *head) {
    unordered_set<ListNode*> set;
    while (head != NULL) {
        auto pair = set.insert(head);
        if (!pair.second) return head;
        head = head->next;
    }
    return NULL;
}

// 快慢指针解法 数学做法，难点在于找到进入循环的点
ListNode *detectCycle(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *a1 = head, *a2 = head;
    while(a2 != NULL) {
        a1 = a1->next;
        a2 = a2->next;
        if (a2 == NULL) return NULL;
        a2 = a2->next;
        if (a1 == a2) {
            while(head != a1) {
                head = head->next;
                a1 = a1->next;
            }
            return head;
        }
    }
    return NULL;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}