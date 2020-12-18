#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/17
 * @description: 589.n-ary-tree-preorder-traversal
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


vector<int> preorder(Node* root) {
    vector<int> r;
    if (root == NULL) return r;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        auto top = s.top();
        s.pop();
        r.push_back(top->val);
        for (int i = top->children.size() - 1; i >= 0; i--) s.push(top->children[i]);
    }
    return r;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}