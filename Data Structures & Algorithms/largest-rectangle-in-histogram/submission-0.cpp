class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> leftStack;
        stack<int> rightStack;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);

        // left
        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() && heights[i] <= heights[leftStack.top()]) leftStack.pop();
            leftStack.empty() ? left[i] = -1 : left[i] = leftStack.top();
            leftStack.push(i);
        }

        // right
        for (int i = n - 1; i >= 0; i--) {
            while (!rightStack.empty() && heights[i] <= heights[rightStack.top()]) rightStack.pop();
            rightStack.empty() ? right[i] = n : right[i] = rightStack.top();
            rightStack.push(i);
        }

        // ans cal
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
