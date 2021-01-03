#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/3
 * @description: 
 */
int MOD = 1000000007;

int countPairs(vector<int> &deliciousness) {
    vector<int> V;
    int t = 1;
    V.push_back(0);
    V.push_back(t);
    for (int i = 0; i <= 21; i++) {
        t *= 2;
        V.push_back(t);
    }
    unordered_map<int, int> M;
    int ans = 0, size = deliciousness.size();
    for (int i = 0; i < size; i++) {
        auto temp = M.find(deliciousness[i]);
        if (temp != M.end()) {
            ans += temp->second;
            ans %= MOD;
        }
        for (auto j : V) {
            int k = j - deliciousness[i];
            if (k < 0) continue;
            if (deliciousness[i] == 0 && k == 0) continue;
            M[k]++;
        }
    }
    return ans;
}

int main() {
//    vector<int> b{1,3,5,7,9, 0,0};
    vector<int> b{2,14,11,5,1744,2352,0,1,1300,2796,0,4,376,1672,73,55,2006,42,10,6,0,2,2,0,0,1,0,1,0,2,271,241,1,63,1117,931,3,5,378,646,2,0,2,0,15,1};

    int a = countPairs(b);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}