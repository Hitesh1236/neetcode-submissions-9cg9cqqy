class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> map;
        map['('] = ')';
        map['{'] = '}';
        map['['] = ']';
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        for(char x:s){
            if(x == ')' || x == '}' || x == ']'){
                if(st.empty() || st.top()!=map[x]) return false;
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
