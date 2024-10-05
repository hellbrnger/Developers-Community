#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    // Push operation 
    void push(int x) {
        // Push element into q2
        q2.push(x);

        // Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        swap(q1, q2);
    }

    // Pop operation
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop(); // remove the front element
    }

    // Top operation (returns top element)
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front(); // top of the stack is front of q1
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl; // Should print 3
    s.pop();

    cout << "Top element after pop: " << s.top() << endl; // Should print 2
    s.pop();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Should print No

    s.pop();
    cout << "Is stack empty after all pops? " << (s.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}
