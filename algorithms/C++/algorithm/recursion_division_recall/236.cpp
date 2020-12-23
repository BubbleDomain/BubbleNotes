#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/21
 * @description: 236.lowest-common-ancestor-of-a-binary-tree
 *
 * **尽量别进行回溯，一遍递归完成**
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeStatus {
    TreeNode *node;
    bool isLeft;

    TreeStatus(TreeNode* node) : node(node), isLeft(true) {}
};

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

struct Node {
    TreeNode* node;
    int layer;

    Node(TreeNode* node, int layer) : node(node), layer(layer) {}
};

vector<Node> P;
vector<Node> Q;

void recurse(TreeNode* node, TreeNode* p, TreeNode* q, vector<Node> t, int layer) {
    if (node == NULL) return;
    t.emplace_back(node, layer);
    if (node == p) {
        P = t;
        if (!Q.empty()) return;
    } else if (node == q) {
        Q = t;
        if (!P.empty()) return;
    }
    recurse(node->left, p, q, t, layer + 1);
    recurse(node->right, p, q, t, layer + 1);
}

// 解法一：超时 先深度优先遍历，找到root到p、q的链路，再从链路中找到最近祖先
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    recurse(root, p, q, {}, 1);
    for(auto i = P.rbegin(), j = Q.rbegin(); i != P.rend() && j != P.rend();) {
        if (i->layer == j->layer && i->node == j->node) {
            return i->node;
        } else if (i->layer > j->layer) {
            i++;
        } else {
            j++;
        }
    }
    return NULL;
}

// 解法二 不进行回溯
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    if (root == p) return p;
    if (root == q) return q;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL && right != NULL) return right;
    if (left != NULL && right == NULL) return left;
    if (left != NULL && right != NULL) return root;
    return NULL;
}

int main() {
    auto TN = deserialize("[3,5,1,6,2,0,8,null,null,7,4]");
    auto r = lowestCommonAncestor(TN, TN->left, TN->left->right->right);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}