#include <iostream>
#include <vector>
#include <stack>
#include <deque>

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

// 数组记录
vector<vector<int>> levelOrder1(Node* root) {
    vector<vector<int>> r;
    vector<Node*> s;
    if (root == NULL) return r;
    s.push_back(root);
    while(!s.empty()) {
        vector<Node*> t;
        vector<int> t1;
        for (auto i : s) {
            t1.push_back(i->val);
            for (auto child : i->children) {
                t.push_back(child);
            }
        }
        r.push_back(t1);
        s = t;
    }
    return r;
}

// 队列记录
vector<vector<int>> levelOrder2(Node* root) {
    vector<vector<int>> r;
    deque<Node*> d;
    if (root == NULL) return r;
    d.push_back(root);
    while(!d.empty()) {
        auto i = d.front();
        vector<int> v;
        while(i != NULL && i != root) {
            for (auto j : i->children) d.push_back(j);
            v.push_back(i->val);
            d.pop_front();
            if (d.empty()) break;
            i = d.front();
        }
        for (auto j : i->children) d.push_back(j);
        v.push_back(i->val);
        d.pop_front();
        root = d.back();
        r.push_back(v);
    }
    return r;
}

// 队列记录 优化 但其实速度并不快，虽然代码看起来优化了，但是deque的size方法是很耗时的
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> r;
    deque<Node*> d;
    if (root == NULL) return r;
    d.push_back(root);
    while(!d.empty()) {
        vector<int> v;
        // **确定队列分界点**
        int size = d.size();
        for (int i = 0; i < size; i++) {
            auto top = d.front();
            d.pop_front();
            v.push_back(top->val);
            for (auto j : top->children) d.push_back(j);
        }
        r.push_back(v);
    }
    return r;
}

int main() {
    Node* a[] = {new Node(2), new Node(3)};
    vector<Node*> aa(a, a+2);
    Node* c = new Node(1, aa);
    levelOrder(c);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
