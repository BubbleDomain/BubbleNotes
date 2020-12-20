#include <iostream>
#include <stack>
#include <queue>

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "[]";
        queue<TreeNode*> Q;
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
    TreeNode* deserialize(string data) {
        int size = data.length();
        for (int i = 1; i < size - 1; i++) {
            char c = data[i];
            if (c >= '0' && c <= '9') {
                vector<int> v(1, c - '0');
                i++;
                while (data[i] >= '0' && data[i] <= '9') v.push_back(data[i++]);
                int s = v.size();
                for (auto j : v) {
                    // todo 转数字
                }
            } else if (c == 'n') {

            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}