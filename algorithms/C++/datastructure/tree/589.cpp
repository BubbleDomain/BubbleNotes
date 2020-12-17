#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/17
 * @description: 589.n-ary-tree-preorder-traversal
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


vector<int> preorder(Node* root) {

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}