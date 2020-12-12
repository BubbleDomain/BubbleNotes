#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/11
 * @description: 25.reverse-nodes-in-k-group
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

void converse(ListNode *head, ListNode *tail) {
    if (head == NULL) return;
    ListNode *pre = NULL, *post = head;
    while (post != tail) {
        ListNode *temp = post->next;
        post->next = pre;
        pre = post;
        post = temp;
    }
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) return head;
    ListNode *pre = NULL, *post = head, *result = head;
    int i = 1;
    bool isFirst = true;
    // 每次找k个数，不足直接返回
    while (post != NULL) {
        if (i == k) {
            ListNode *temp = post->next;
            // 找到就链表翻转
            converse(head, temp);
            if (isFirst) {
                result = post;
                isFirst = false;
            } else pre -> next = post;
            pre = head;
            pre->next = temp;
            post = temp;
            head = temp;
            i = 1;
        }
        if (post == NULL) break;
        post = post->next;
        i++;
    }
    return result;
}

int main() {
    int a[] = {1, 2};
    vector<int> aa(a, a+2);
    auto b = new ListNode(aa);
    auto c = reverseKGroup(b, 2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}