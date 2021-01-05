#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/5
 * @description: 515.find-largest-value-in-each-tree-row
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    if (root == NULL) return ans;
    queue<TreeNode *> Q;
    Q.push(root);
    TreeNode *end = root;
    int temp = INT32_MIN;
    while (!Q.empty()) {
        auto front = Q.front();
        while (true) {
            temp = max(temp, front->val);
            Q.pop();
            if (front->left != NULL)Q.push(front->left);
            if (front->right != NULL)Q.push(front->right);
            if (front == end) break;
            front = Q.front();
        }
        end = Q.back();
        ans.push_back(temp);
        temp = INT32_MIN;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}