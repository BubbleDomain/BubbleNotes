#include <iostream>
#include <unordered_map>
#include <set>
#include <list>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/2/28
 * @description: 460.lfu-cache
 */
// 哈希表+红黑树
// 哈希表记录元数据
// 红黑树用来给所有节点排序
struct Node1 {
    // 使用次数
    int count;
    // 最近一次使用
    int time;
    int key, value;

    Node1(int _count, int _time, int _key, int _value) : count(_count), time(_time), key(_key), value(_value) {}
    bool operator < (const Node1& node) const {
        return node.count == count ? time < node.time : count < node.count;
    }
};

class LFUCache1 {
public:
    int _capacity, time;
    unordered_map<int, Node1> M;
    set<Node1> S;

    LFUCache1(int capacity) {
        _capacity = capacity;
        time = 0;
        M.clear();
        S.clear();
    }

    int get(int key) {
        if (_capacity == 0) return -1;
        time++;
        auto entry = M.find(key);
        if (entry == M.end()) return -1;
        auto node = entry->second;
        S.erase(node);
        node.time = time;
        node.count++;
        S.insert(node);
        entry->second = node;
        return node.value;
    }

    void put(int key, int value) {
        if (_capacity == 0) return;
        time++;
        auto entry = M.find(key);
        if (entry == M.end()) {
            if (M.size() == _capacity) {
                auto node = S.begin();
                M.erase(node->key);
                S.erase(node);
            }
            auto node = Node1(1, time, key, value);
            M.insert(make_pair(key, node));
            S.insert(node);
        } else {
            auto node = entry->second;
            S.erase(node);
            node.time = time;
            node.count++;
            node.value = value;
            S.insert(node);
            entry->second = node;
        }
    }
};

// 双哈希表
// 一个哈希表记录元数据
// 另一个用来排序，key为使用频率，value为元数据链表，使用链表可以自然获取到同一使用频率最久未使用的节点。
struct Node {
    // 使用次数
    int count;
    int key, value;

    Node(int _count, int _key, int _value) : count(_count), key(_key), value(_value) {}
};

class LFUCache {
public:
    int _capacity, minCount;
    unordered_map<int, list<Node>::iterator> metas;
    unordered_map<int, list<Node>> lists;
    LFUCache(int capacity) {
        _capacity = capacity;
        minCount = 0;
        metas.clear();
        lists.clear();
    }

    int get(int key) {
        if (_capacity == 0) return -1;
        auto i = metas.find(key);
        if (i == metas.end()) return -1;
        auto node = i->second;
        int cnt = node->count, value = node->value;
        lists[cnt].erase(node);
        if (lists[cnt].size() == 0) {
            lists.erase(cnt);
            if (minCount == cnt) minCount++;
        }
        lists[cnt + 1].push_front(Node(cnt + 1, key, value));
        metas[key] = lists[cnt + 1].begin();
        return value;
    }

    void put(int key, int value) {
        if (_capacity == 0) return;
        auto i = metas.find(key);
        if (i == metas.end()) {
            if (metas.size() == _capacity) {
                auto willDelete = lists[minCount].back();
                metas.erase(willDelete.key);
                lists[minCount].pop_back();
                if (lists[minCount].size() == 0) lists.erase(minCount);
            }
            lists[1].push_front(Node(1, key, value));
            metas[key] = lists[1].begin();
            minCount = 1;
        } else {
            auto node = i->second;
            int cnt = node->count;

            list<Node> l = lists[cnt];
            l.erase(node);
            if (lists[cnt].size() == 0) {
                lists.erase(cnt);
                if (minCount == cnt) minCount++;
            }
            lists[cnt + 1].push_front(Node(cnt + 1, key, value));
            metas[key] = lists[cnt + 1].begin();
        }
    }
};


int main() {
    unordered_map<int, list<Node>> lists;
    lists[2].push_back(Node(1,1,1));
    auto a = lists[2];
    a.back().value = 2;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}