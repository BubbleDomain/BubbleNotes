#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/17 2:08 下午
 * @description: 94.binary-tree-inorder-traversal
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

// 非递归解法 思路有点过于复杂了下面有简化版 但这是这几个里面速度最快的
vector<int> inorderTraversal1(TreeNode* root) {
    stack<TreeNode*> S;
    unordered_set<TreeNode*> t;
    S.push(root);
    vector<int> r;
    while(!S.empty() && root != NULL) {
        TreeNode* top = S.top();
        S.pop();
        if ((top->left == NULL && top->right == NULL) || (!t.empty() && t.find(top->left) != t.end())
                || (!S.empty() && top->right == S.top())) {
            t.insert(top);
            r.push_back(top->val);
            continue;
        }
        if (top->right != NULL) S.push(top->right);
        S.push(top);
        if (top->left != NULL) S.push(top->left);
    }
    return r;
}

void middle(vector<int> &r, TreeNode* node) {
    if (node->left != NULL) middle(r, node->left);
    r.push_back(node->val);
    if (node->right != NULL) middle(r, node->right);
}

// 递归解法
vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> r;
    if (root != NULL) middle(r, root);
    return r;
}

// 非递归简化版 还是丑陋
vector<int> inorderTraversal3(TreeNode* root) {
    stack<TreeNode*> S;
    S.push(root);
    vector<int> r;
    while(!S.empty() && root != NULL) {
        auto top = S.top();
        while(top->left != NULL) {
            S.push(top->left);
            top = S.top();
        }
        while(top->right == NULL) {
            S.pop();
            r.push_back(top->val);
            if (S.empty()) return r;
            top = S.top();
        }
        S.pop();
        r.push_back(top->val);
        if (top->right != NULL) S.push(top->right);
    }
    return r;
}

// 非递归简化版 优化版
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> r;
    while(!S.empty() || root != NULL) {
        while(root != NULL) {
            S.push(root);
            root = root->left;
        }
        auto top = S.top();
        S.pop();
        r.push_back(top->val);
        root = top->right;
    }
    return r;
}

int main() {
    auto *a3 = new TreeNode(2);
    auto *a2 = new TreeNode(1, NULL, a3);
    auto *a1 = new TreeNode(3, a2, NULL);
    auto result = inorderTraversal(a1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
