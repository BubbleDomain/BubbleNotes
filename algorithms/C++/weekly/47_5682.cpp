#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/6
 * @description: 
 */
struct Node {
    char value;
    int time;
    Node(char _value, int _time) : value(_value), time(_time) {}

    bool operator < (const Node& node) const {
        return time == node.time ? value < node.value : time < node.time;
    }
};
int beautySum(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        unordered_map<char, set<Node>::iterator> keys;
        set<Node> nodes;
        for (int j = i; j < s.length(); j++) {
            auto key = keys.find(s[j]);
            if (key == keys.end()) {
                Node node(s[j], 1);
                auto t = nodes.insert(node);
                if (t.second) keys.insert(make_pair(s[j], t.first));
            } else {
                auto node = key->second;
                Node nodeNew(s[j], node->time + 1);
                keys.erase(s[j]);
                nodes.erase(node);
                auto t = nodes.insert(nodeNew);
                if (t.second) keys.insert(make_pair(s[j], t.first));
            }
            sum += (nodes.rbegin()->time - nodes.begin()->time);
        }
    }
    return sum;
}

int main() {
    int a = beautySum("aabcb");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}