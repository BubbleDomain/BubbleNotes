#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 297.serialize-and-deserialize-binary-tree
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

struct TreeStatus {
    TreeNode *node;
    bool isLeft;

    TreeStatus(TreeNode* node) : node(node), isLeft(true) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode *root) {
    if (root == NULL) return "[]";
    queue<TreeNode *> Q;
    string result = "[";
    Q.push(root);
    while (!Q.empty()) {
        auto top = Q.front();
        result += (top == NULL ? "null" : to_string(top->val));
        result += ',';

        Q.pop();
        if (top == NULL) continue;
        Q.push(top->left);
        Q.push(top->right);
    }
    result.erase(result.length() - 1);
    result += "]";
    return result;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data) {
    int size = data.length();
    TreeNode* root = NULL;
    if (data == "[]") return root;
    queue<TreeStatus> Q;
    for (int i = 1; i < size - 1; i++) {
        char c = data[i];
        if (c == '-' || (c >= '0' && c <= '9')) {
            int flag = false;
            if (c == '-') {
                flag = true;
                c = data[++i];
            }
            vector<int> v(1, c - '0');
            i++;
            while (data[i] >= '0' && data[i] <= '9') v.push_back(data[i++] - '0');
            int s = v.size(), t = 0;
            for (int j = 0; j < s; j++) {
                t += v[j] * pow(10, s - j - 1);
            }
            auto tNode = new TreeNode(flag ? -t : t);

            // 处理数字
            if (Q.empty()) {
                root = tNode;
                Q.push({tNode});
                continue;
            }
            auto top = Q.front();
            if (top.isLeft) {
                top.node->left = tNode;
                Q.front().isLeft = false;
            } else {
                top.node->right = tNode;
                Q.pop();
            }
            Q.push({tNode});
        } else if (c == 'n') {
            // 处理null
            if (Q.front().isLeft) {
                Q.front().isLeft = false;
            } else {
                Q.pop();
            }
            i += 4;
        }
    }
    return root;
}

int main() {
    auto a = deserialize("[1,9,2,8,10]");

    return 0;
}