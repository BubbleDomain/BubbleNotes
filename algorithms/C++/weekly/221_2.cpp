#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/27
 * @description:
 *
 *
 * 学习这种数据处理方式，堆结构
 * 优先队列存放的是[腐烂日期, 苹果数量]
 * priority_queue
 * PriorityQueue<int[]> queue
 */
int eatenApples(vector<int>& apples, vector<int>& days) {
    int ans = 0;
    unordered_map<int, int> table;
    vector<int> orderedDate;
    for (int i = 0; i < apples.size(); i++) {
        int apple = apples[i], date = i + days[i];
        if (apple != 0) {
            table[date] += apple;
            int s = orderedDate.size();
            for (int j = 0; j < s; j++) {
                if (orderedDate[j] == date) break;
                if (orderedDate[j] > date) {
                    orderedDate.insert(orderedDate.begin(), date);
                    break;
                }
                if (orderedDate[j] < date && (j + 1 == s || orderedDate[j + 1] > date)) {
                    orderedDate.insert(orderedDate.begin() + j + 1, date);
                    break;
                }
            }
            if (s == 0) orderedDate.push_back(date);
        }

        if (orderedDate.empty()) continue;
        int top = orderedDate.front();
        // 过期的删除
        if (top == i) {
            orderedDate.erase(orderedDate.begin());
            if (orderedDate.empty()) continue;
            top = orderedDate.front();
        }
        table[top]--;
        if (table[top] == 0) orderedDate.erase(orderedDate.begin());
        ans++;
    }
    int time = apples.size();
    while(!orderedDate.empty()) {
        if (orderedDate.empty()) continue;
        int top = orderedDate.front();
        // 过期的删除
        if (top == time) {
            orderedDate.erase(orderedDate.begin());
            if (orderedDate.empty()) continue;
            top = orderedDate.front();
        }
        table[top]--;
        if (table[top] == 0) orderedDate.erase(orderedDate.begin());
        ans++;
        time++;
    }
    return ans;
}

int main() {
    vector<int> a {3,10,10};
    vector<int> b {4,1,30};
    int c = eatenApples(a,b);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}