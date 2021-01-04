#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/4
 * @description: 102.binary-tree-level-order-traversal
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode* temp = root;
    while (!Q.empty()) {
        vector<int> t;
        TreeNode* i = Q.front();
        while(true) {
            t.push_back(i->val);
            Q.pop();
            if (NULL != i->left) Q.push(i->left);
            if (NULL != i->right) Q.push(i->right);
            if (i == temp) {
                temp = Q.back();
                break;
            }
            i = Q.front();
        }
        ans.push_back(t);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}