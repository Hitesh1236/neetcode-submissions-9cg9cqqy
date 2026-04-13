class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            int m = strs[i].size();
            ans += to_string(m);
            ans += '#';
            for(int j = 0; j < m; j++){
                ans.push_back(strs[i][j]);
            }
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> ans;
        int i = 0;
        while(i < n && s[i]!='#'){
            string nums = "";
            while(s[i]!='#'){
                nums += s[i];
                i++;
            }
            i++;
            int num = stoi(nums);
            int count = 0;
            string res = "";
            while(count < num){
                res.push_back(s[i]);
                count++;
                i++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
