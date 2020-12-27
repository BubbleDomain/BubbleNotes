#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/26
 * @description: 
 */
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int stu = 0, sand = 0, sandSize = sandwiches.size();
    while(sand < sandSize) {
        int sFront = sandwiches[sand];
        bool flag = true;
        int stuSize = students.size();
        for (int i = 0; i < stuSize; i++) {
            stu %= stuSize;
            int front = students[stu];
            if (front == sFront) {
                flag = false;
                sand++;
                students.erase(students.begin() + stu);
                stu = (stu + 1) % stuSize;
                break;
            }
            stu = (stu + 1) % stuSize;
        }
        if (flag) break;
    }
    return sandSize - sand;
}

int main() {
    vector<int> a {1,1,1,0,0,1};
    vector<int> b {1,0,0,0,1,1};
    int c = countStudents(a, b);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}