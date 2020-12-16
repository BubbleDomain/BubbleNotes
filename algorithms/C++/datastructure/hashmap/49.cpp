#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/16 5:08 下午
 * @description: 49.group-anagrams
 *
 * **这道题主要学习最后两种方法的思路**
 *
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

// 耗时太长，对比时有重复操作
vector<vector<string>> groupAnagrams1(vector<string>& strs) {
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

vector<int> getV(string s) {
    vector<int> r(27, 0);
    r[26] = s.length();
    for (auto i : s) r[i - 'a']++;
    return r;
}

bool isS(vector<int> v, string s) {
    if (v[26] != s.length()) return false;
    vector<int> temp(26, 0);
    for (auto c : s) temp[c - 'a']++;
    for (int i = 0; i < 26; i++) if (temp[i] != v[i]) return false;
    return true;
}

// 耗时太长，优化后还是不乐观
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    vector<vector<string>> r;
    vector<vector<int>> result;

    for (const auto& str : strs) {
        if (result.empty()) {
            r.emplace_back(1, str);
            result.push_back(getV(str));
            continue;
        }
        bool hasCluster = false;

        for (int i = 0; i < result.size(); i++) {
            if (isS(result[i], str)) {
                r[i].push_back(str);
                hasCluster = true;
                break;
            }
        }
        if (!hasCluster) {
            r.emplace_back(1, str);
            result.push_back(getV(str));
        }
    }
    return r;
}

// 方法一: 统计string中的字符转换成后面这样的字符串"a2b3c3"
// 方法二: 对应每个小写字母找一个素数一一对应，然后全部乘起来，对比即可，这个思路更加数学
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> r1;
    vector<vector<string>> r2;
    for (auto str : strs) {
        string t = "";
        vector<int> v(26, 0);
        for (char c : str) v[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (v[i] == 0) continue;
            t += i;
            t += v[i];
        }
        bool flag = true;
        for (int i = 0; i < r1.size(); i++) {
            if (r1[i] == t) {
                r2[i].push_back(str);
                flag = false;
                break;
            }
        }
        if (flag) {
            r1.push_back(t);
            r2.emplace_back(1, str);
        }
    }
    return r2;
}

void logTime() {
    time_t now = time(0);

    // 把 now 转换为字符串形式
    char* dt = ctime(&now);

    cout << "本地日期和时间：" << dt << endl;
}

int main() {
    string a[] = {};
    vector<string> aa(a, a);
    auto t1 = clock();
    string x = "";
    x += "123";
    x += '4';
    x += (4 + '1');
//    auto r = groupAnagrams(aa);
    auto t2 = clock();
    double d = (t2 - t1) / CLOCKS_PER_SEC;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
