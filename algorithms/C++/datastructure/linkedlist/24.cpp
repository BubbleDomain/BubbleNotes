#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 24.swap-nodes-in-pairs
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 临时变量很多容易出错
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *a1 = head, *a2 = head->next, *r = a2, *lastEnd = NULL;
    while(a2 != NULL) {
        ListNode *t = a2->next;
        a2->next = a1;
        a1->next = t;
        if (lastEnd != NULL) lastEnd->next = a2;
        lastEnd = a1;
        a1 = t;
        if (t == NULL) break;
        a2 = t->next;
    }
    return r;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}