class MinStack {
    Stack s1 = new Stack();
    Stack s2 = new Stack();
    
    public void push(int x) {
        if(x <= getMin()) s2.push(x);
        s1.push(x);
    }

    public void pop() {
        if(s1.peek().equals(s2.peek()) ) s2.pop();
        s1.pop();
    }

    public int top() {
        return (int)s1.peek();
    }

    public int getMin() {
        if(s2.empty()) return Integer.MAX_VALUE;
        return (int)s2.peek();
    }
}