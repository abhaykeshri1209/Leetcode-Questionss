class MyQueue {
public:
stack<int>input;
stack<int>output;
    MyQueue() {
        
    } void moveToOutput() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

   
    void push(int x) {
       input.push(x);
    }
    
    int pop() {
          moveToOutput();

        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
         moveToOutput();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */