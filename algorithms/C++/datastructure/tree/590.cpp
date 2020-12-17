#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/17 5:38 下午
 * @description: 590.n-ary-tree-postorder-traversal
 */
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void post(vector<int> &r, Node* node) {
    for (auto child : node->children) {
        post(r, child);
    }
    r.push_back(node->val);
}

// 递归法
vector<int> postorder1(Node* root) {
    vector<int> r;
    if (root != NULL) post(r, root);
    return r;
}

// 非递归法较难想到
// 考虑到后序遍历其实等价于【翻转树的先序遍历倒置】
vector<int> postorder(Node* root) {
    vector<int> r;
    stack<Node*> s;
    if (root == NULL) r;
    while(!s.empty() || root != NULL) {
        while(root->children.size() > 0) {
            r.push_back(root);
            root = root
        }
    }
    return r;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
