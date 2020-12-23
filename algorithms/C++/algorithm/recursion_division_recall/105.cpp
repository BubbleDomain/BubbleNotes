#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/22
 * @description: 105.construct-binary-tree-from-preorder-and-inorder-traversal
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) return NULL;
    if (preorder.size() == 1) return new TreeNode(preorder.front());

    int no = find(inorder.begin(), inorder.end(), preorder.front()) - inorder.begin();
    vector<int> lPre(preorder.begin() + 1, preorder.begin() + 1 + no);
    vector<int> lIn(inorder.begin(), inorder.begin() + no);
    vector<int> rPre(preorder.begin() + no + 1, preorder.end());
    vector<int> rIn(inorder.begin() + no + 1, inorder.end());
    return new TreeNode(preorder.front(), buildTree(lPre, lIn), buildTree(rPre, rIn));
}

int main() {
    //前序遍历 preorder = []
    //中序遍历 inorder = []
    int a[] = {3,9,20,15,7};
    vector<int> aa(a, a+5);
    int b[] = {9,3,15,20,7};
    vector<int> bb(b, b+5);
    auto c = buildTree(aa, bb);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}