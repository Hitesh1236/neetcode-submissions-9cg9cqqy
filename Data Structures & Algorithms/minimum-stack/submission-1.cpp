class MinStack {
    stack<int> st;
    stack<int> mst;

   public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) mst.push(val);
        else mst.push(min(val, mst.top()));
        st.push(val);
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
        mst.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    int getMin() {
        if(st.empty()) return -1;
        return mst.top();
    }
};
