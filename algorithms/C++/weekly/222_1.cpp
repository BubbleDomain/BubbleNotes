#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/3
 * @description: 
 */
struct Data {
    int sum;
    int quality;
    Data() {}
    Data(int a, int b) : sum(a), quality(b) {}
};

static bool cmp(Data a, Data b) {
    return a.quality > b.quality;
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    vector<Data> datas;
    datas.reserve(boxTypes.size());
    for (auto box : boxTypes) datas.emplace_back(box[0], box[1]);
    sort(datas.begin(), datas.end(), cmp);
    int sum = 0, size = 0;
    auto i = datas.begin();
    while (size <= truckSize && i != datas.end()) {
        for (int j = 0; j < i->sum; j++) {
            size++;
            if (size > truckSize) {
                return sum;
            }
            sum += i->quality;
        }
        i++;
    }
    return sum;
}

int main() {
    vector<vector<int>> a {{1,3},{2,2},{3,1}};
    int b= maximumUnits(a, 4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}