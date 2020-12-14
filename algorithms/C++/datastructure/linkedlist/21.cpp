#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/14
 * @description: 21.merge-two-sorted-lists
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(vector<int> v) {
        val = v[0];
        int size = v.size();
        if (size == 1) return;
        auto last(new ListNode(0));
        next = last;
        for (int i = 1; i < size; i++) {
            last->val = v[i];
            if (i == size - 1) return;
            auto t = new ListNode(1);
            last->next = t;
            last = t;
        }
    }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode *start, *current;
    if (l1->val > l2->val) {
        start = l2;
        l2 = l2->next;
    } else {
        start = l1;
        l1 = l1->next;
    }
    current = start;
    while(l1 != NULL || l2 != NULL) {
        if (l1 == NULL || (l2 != NULL && l1->val >= l2->val)) {
            current->next = l2;
            l2 = l2->next;
        } else if (l2 == NULL || (l1 != NULL && l2->val >= l1->val)) {
            current->next = l1;
            l1 = l1->next;
        }
        current = current->next;
    }
    return start;
}

int main() {
    int a[] = {1,2,4};
    vector<int> aa(a, a + 3);
    int b[] = {1,3,4};
    vector<int> bb(b, b + 3);
    auto c = mergeTwoLists(new ListNode(aa), new ListNode(bb));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}