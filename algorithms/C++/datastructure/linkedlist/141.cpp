#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/10
 * @description: 141.linked-list-cycle
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 法一：标记法
bool hasCycle0(ListNode *head) {
    while(head != NULL) {
        head->val = 106;
        head = head->next;
        if (head == NULL) return false ;
        else if (head->val == 106) return true;
    }
    return false;
}

// 法二：快慢指针
bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode* pre = head;
    ListNode* post = head->next;
    while(post != NULL) {
        if (pre == post) return true;
        pre = pre->next;
        post = post->next;
        if (post == NULL) break;
        post = post->next;
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
