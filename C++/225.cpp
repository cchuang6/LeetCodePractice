class Stack {
public:
    // Push element x onto stack.
    queue<int> q;
    
    //using push expensive
    void push(int x) {
        q.push(x);
        int size = q.size();
        for(int i = 1; i < size; i++ ){
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};