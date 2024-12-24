Ques 2. Given a queue, write a recursive function to reverse it. 
Standard operations allowed : 
enqueue(x) : Add an item x to rear of queue. 
dequeue() : Remove an item from front of queue. 
empty() : Checks if a queue is empty or not.

Program code:
#include <iostream>
#include <queue>
void reverseQueue(std::queue<int>& q) {
    if (q.empty()) {
        return;
    }
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}
void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}
int main() {
    std::queue<int> q;
    int arr1[] = {5, 24, 9, 6, 8, 4, 1, 8, 3, 6};
    for (int i : arr1) {
        q.push(i);
    }
    std::cout << "Original Queue: ";
    printQueue(q);
    reverseQueue(q);
    std::cout << "Reversed Queue: ";
    printQueue(q);
    int arr2[] = {8, 7, 2, 5, 1};
    std::queue<int> q2;
    for (int i : arr2) {
        q2.push(i);
    }
    std::cout << "Original Queue: ";
    printQueue(q2);
    reverseQueue(q2);
    std::cout << "Reversed Queue: ";
    printQueue(q2);
    return 0;
}
