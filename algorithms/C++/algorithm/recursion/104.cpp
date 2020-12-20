#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 104.maximum-depth-of-binary-tree
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

int result = 0;

void recurse(TreeNode* node, int deep) {
    if (node == NULL) {
        result = max(result, deep);
        return;
    }
    deep++;
    recurse(node->right, deep);
    recurse(node->left, deep);
}

int maxDepth(TreeNode* root) {
    recurse(root, 0);
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}