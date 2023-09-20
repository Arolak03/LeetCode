class MinStack {
public:
    vector<int> s;
    vector<int> minStack; // to store the minimum values

    MinStack() {
    }

    void push(int val) {
        s.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    void pop() {
        if (!s.empty()) {
            if (s.back() == minStack.back()) {
                minStack.pop_back();
            }
            s.pop_back();
        }
    }

    int top() {
        if (!s.empty()) {
            return s.back();
        }
        return -1; // Handle the case when the stack is empty
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.back();
        }
        return -1; // Handle the case when the stack is empty
    }
};
