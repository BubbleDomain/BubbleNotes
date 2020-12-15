#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/15
 * @description: 641.design-circular-deque
 */
class MyCircularDeque {
private:
    vector<int> content;
    int size = 0;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (content.size() == size) return false;
        content.insert(content.begin(), value);
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (content.size() == size) return false;
        content.insert(content.end(), value);
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (content.size() == 0) return false;
        content.erase(content.begin());
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (content.size() == 0) return false;
        content.erase(content.end() - 1);
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (content.size() == 0) return -1;
        return *content.begin();
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (content.size() == 0) return -1;
        return *(content.end() - 1);
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return content.empty();
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return content.size() == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main() {
    MyCircularDeque circularDeque(3); // 设置容量大小为3
    circularDeque.insertLast(1);			        // 返回 true
    circularDeque.insertLast(2);			        // 返回 true
    circularDeque.insertFront(3);			        // 返回 true
    circularDeque.insertFront(4);			        // 已经满了，返回 false
    circularDeque.getRear();  				// 返回 2
    circularDeque.isFull();				        // 返回 true
    circularDeque.deleteLast();			        // 返回 true
    circularDeque.insertFront(4);			        // 返回 true
    circularDeque.getFront();				// 返回 4

    std::cout << "Hello, World!" << std::endl;
    return 0;
}