#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 226.invert-binary-tree
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

void recurse(TreeNode* node) {
    if (node == NULL) return;
    auto t = node->left;
    node->left = node->right;
    node->right = t;
    recurse(node->left);
    recurse(node->right);
}


TreeNode* invertTree(TreeNode* root) {
    recurse(root);
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}