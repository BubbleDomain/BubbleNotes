#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/26
 * @description: 860.lemonade-change
 */
bool lemonadeChange(vector<int>& bills) {
    int money[] = {5, 10, 20};
    map<int, int> wallet = {{5, 0}, {10, 0}, {20, 0}};
    for (auto bill: bills) {
        int t = bill;
        bill -= 5;
        while(bill > 0) {
            int flag = true;
            for (int i = 2; i >= 0; i--) {
                if (bill >= money[i] && wallet[money[i]] > 0) {
                    wallet[money[i]]--;
                    bill -= money[i];
                    flag = false;
                    break;
                }
            }
            if (flag) return false;
        }
        wallet[t]++;
    }

    return true;
}

int main() {
    vector<int> a = {5,5,5,10,20};
    bool ans = lemonadeChange(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}