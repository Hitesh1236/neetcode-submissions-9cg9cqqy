class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> ans;
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int res;
                int n1 = ans.top();
                ans.pop();
                int n2 = ans.top();
                ans.pop();
                if(tokens[i] == "+") res = n1 + n2;
                else if(tokens[i] == "-") res = n2 - n1;
                else if(tokens[i] == "*") res = n1 * n2;
                else res = n2 / n1;
                ans.push(res);
            }
            else{
                int num = stoi(tokens[i]);
                ans.push(num);
            }
        }
        return ans.top();
    }
};
