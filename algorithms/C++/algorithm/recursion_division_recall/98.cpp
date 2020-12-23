#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 98.validate-binary-search-tree
 * **思路二很重要**
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

pair<int, int> recurse(TreeNode* node, bool &result) {
    if (node->left == NULL && node->right == NULL) return {node->val, node->val};
    else if (node->left == NULL) {
        auto right = recurse(node->right, result);
        if (node->val >= right.first) result = false;
        return {node->val, right.second};
    } else if (node->right == NULL) {
        auto left = recurse(node->left, result);
        if (left.second >= node->val) result = false;
        return {left.first, node->val};
    }
    auto l = recurse(node->left, result);
    auto r = recurse(node->right, result);
    if (l.second >= node->val || node->val >= r.first) result = false;
    return {l.first, r.second};
}

// 思路一: 反向传递范围到上面 不是很好
bool isValidBST1(TreeNode* root) {
    bool result = true;
    if (root != NULL) recurse(root, result);
    return result;
}

// root符合[min, max]
bool recurse(TreeNode* root, long min, long max) {
    if (root == NULL) return true;
    if (root->val <= min || root->val >= max) return false;
    return recurse(root->left, min, root->val) && recurse(root->right, root->val, max);
}

// 思路二: 子树是否在范围内!!!!
bool isValidBST(TreeNode* root) {
    return recurse(root, LONG_MIN, LONG_MAX);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}