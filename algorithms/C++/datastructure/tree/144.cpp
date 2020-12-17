#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/17 4:41 下午
 * @description: 144.binary-tree-preorder-traversal
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    // todo 层次遍历数组转TreeNode
};

void pre(vector<int> &r, TreeNode *node) {
    r.push_back(node->val);
    if (node->left != NULL) pre(r, node->left);
    if (node->right != NULL) pre(r, node->right);
}

vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> r;
    if (root != NULL) pre(r, root);
    return r;
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> r;
    stack<TreeNode*> s;
    if (root == NULL) return r;
    while(!s.empty() || root != NULL) {
        while(root != NULL) {
            r.push_back(root->val);
            if (root->right != NULL) s.push(root->right);
            root = root->left;
        }
        if (s.empty()) break;
        auto top = s.top();
        s.pop();
        root = top;
    }
    return r;
}

// [2,null,3,null,1]
int main() {
    auto *a3 = new TreeNode(2);
    auto *a2 = new TreeNode(1, NULL, a3);
    auto *a1 = new TreeNode(3, a2, NULL);
//    auto *a3 = new TreeNode(3);
//    auto *a2 = new TreeNode(2, a3, NULL);
//    auto *a1 = new TreeNode(1, NULL, a2);
//    auto *a3 = new TreeNode(1);
//    auto *a2 = new TreeNode(3, NULL, a3);
//    auto *a1 = new TreeNode(2, NULL, a2);
    auto result = preorderTraversal(a1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
