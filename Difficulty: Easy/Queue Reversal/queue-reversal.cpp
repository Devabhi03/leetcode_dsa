class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        // Push all elements into stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        // Pop from stack and push back to queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};