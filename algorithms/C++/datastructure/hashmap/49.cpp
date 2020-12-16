#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/16 5:08 下午
 * @description: 49.group-anagrams
 */
bool isSame(string a, string b) {
    if (a.size() != b.size()) return false;
    unordered_map<int, int> M;
    for (auto c : a) M[c]++;
    for (auto c : b) {
        if (!M[c]) return false;
        M[c]--;
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;

    for (const auto& str : strs) {
        if (result.empty()) {
            result.emplace_back(1, str);
            continue;
        }
        bool hasCluster = false;

        for (int i = 0; i < result.size(); i++) {
            if (isSame(result[i][0], str)) {
                result[i].push_back(str);
                hasCluster = true;
                break;
            }
        }
        if (!hasCluster) result.emplace_back(1, str);
    }
    return result;
}

int main() {
    string a[] = {"eat","tea","tan","ate","nat","bat"};
    vector<string> aa(a, a+6);
    auto r = groupAnagrams(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
