#include <iostream>
#include <stack>

using namespace std;

class Queue_stack {
private:
    stack<int> s1;
    tack<int> s2;

public:
    // push operation
    void enqueue(int x) {
        // Push the element onto stack s1
        s1.push(x);
    }

    // pop operation
    void dequeue() {
        // If both stacks are empty, queue is empty
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Pop the top element from s2 
        s2.pop();
    }

    // Front operation 
    int front() {
        // If both stacks are empty, the queue is empty
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // If s2 is empty, transfer elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top(); 
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue_stack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl; // Should print 10
    q.dequeue();

    cout << "Front element after dequeue: " << q.front() << endl; // Should print 20
    q.dequeue();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print No

    q.dequeue();
    cout << "Is queue empty after all dequeues? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}
