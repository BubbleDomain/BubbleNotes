#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/6
 * @description: 
 */
int mid(vector<int> &table, int n) {
    int l = 0, r = table.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (table[mid] > n) {
            r = mid - 1;
        } else if (table[mid] < n) {
            if (table[mid + 1] == n) {
                return n;
            } else if (table[mid + 1] > n) {
                int t = table[mid];
                table.erase(table.begin() + mid);
                return t;
            }
            l = mid + 1;
        } else {
            return n;
        }
    }
    int t = table[l];
    table.erase(table.begin() + l);
    return t;
}

bool checkPowersOfThree(int n) {
    vector<int> table;
    int maxNum = 10000000;
    for (int i = 1; i <= maxNum; i*=3) {
        table.push_back(i);
    }
    int size = table.size();
    while (n > 0) {
        if (table.empty() || n < table[0]) return false;
        // 寻找小于n的最大3的次幂，注意每个次幂只能用一次
        n -= mid(table, n);
    }
    return true;
}

int main() {
    bool a = checkPowersOfThree(12);
    bool a1 = checkPowersOfThree(91);
    bool a2 = checkPowersOfThree(7475914);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}