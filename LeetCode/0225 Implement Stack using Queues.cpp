class MyStack {
public:
    queue<int> q;

    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};