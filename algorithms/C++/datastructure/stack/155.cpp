#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/14 5:40 下午
 * @description: 155.min-stack
 * 建议使用辅助栈法来解答
 */
// 简单解法，在pop时判断是否需要更新最小值
// 平均效率很高，但是耗时集中在了特殊的pop中
class MinStack1 {
private:
    vector<int> container;
    int m = INT32_MAX;
public:
    /** initialize your data structure here. */
    MinStack1() {}

    void push(int x) {
        container.insert(container.end(), x);
        m = min(m, x);
    }

    void pop() {
        auto temp = container.erase(container.end() - 1);
        if (*temp == m) {
            m = INT32_MAX;
            for (auto i : container) {
                m = min(i, m);
            }
        }
    }

    int top() {
        return *(container.end() - 1);
    }

    int getMin() {
        return m;
    }
};

// 利用辅助栈保存栈的推栈情况下的每个最小值
class MinStack {
private:
    stack<int> container;
    stack<int> support;
public:
    /** initialize your data structure here. */
    MinStack() {
        support.push(INT32_MAX);
    }

    void push(int x) {
        container.push(x);
        support.push(min(support.top(), x));
    }

    void pop() {
        container.pop();
        support.pop();
    }

    int top() {
        return container.top();
    }

    int getMin() {
        return support.top();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
