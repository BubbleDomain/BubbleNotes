#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/18 11:12 上午
 * @description: 429.n-ary-tree-level-order-traversal
 */
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
