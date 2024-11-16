#include <stack>
using namespace std;

class MinStack {
public:
    // Main stack to hold all values
    stack<int> mainStack;
    // Min stack to hold the minimum values
    stack<int> minStack;

    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        // If minStack is empty or val is less than or equal to the current minimum, push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // If the top of mainStack is the same as the top of minStack, pop from minStack
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        // Pop from mainStack
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */