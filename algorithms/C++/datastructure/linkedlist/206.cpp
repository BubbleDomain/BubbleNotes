#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 206.reverse-linked-list
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *a2 = head, *a1 = NULL;
    while(a2 != NULL) {
        ListNode* t = a2->next;
        a2->next = a1;
        a1 = a2;
        a2 = t;
    }
    return a1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}