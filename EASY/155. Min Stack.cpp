#include "leetcode.h"

class MinStack {
private:
    vector<int> stack;
    vector<int> min;
public:
    MinStack() {
    }
    void push(int x) {
        stack.push_back(x);
        
        if (min.empty() || x <= min.back()) {
            min.push_back(x);
        }
    }
    void pop() {
        if(stack.back() == getMin())
            min.pop_back();
        
        stack.pop_back();
    }
    int top() {
        return stack.back();
    }
    int getMin() {
        return min.back();
    }
};

int main() {
    MinStack min_stack;
    min_stack.push(10);
    min_stack.push(20);
    cout << min_stack.getMin() << endl;
    min_stack.push(5);
    cout << min_stack.getMin() << endl;
    min_stack.pop();
    cout << min_stack.getMin() << endl;
}