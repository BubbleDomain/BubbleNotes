#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/17
 * @description: 145.binary-tree-postorder-traversal
 *
 * **特点：后序遍历等价于翻转二叉树前序遍历的反序**
 *
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

// 直接思考非递归 正向思路成本很高，所以直接使用特性 后序遍历等价于翻转二叉树前序遍历的反序
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> r;
    stack<TreeNode*> s;
    if (root == NULL) return r;
    while (root != NULL || !s.empty()) {
        while(root != NULL) {
            r.push_back(root->val);
            if (root->left != NULL) s.push(root);
            root = root->right;
        }
        if (s.empty()) break;
        root = s.top()->left;
        s.pop();
    }
    reverse(r.begin(), r.end());
    return r;
}

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
    auto result = postorderTraversal(a1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}