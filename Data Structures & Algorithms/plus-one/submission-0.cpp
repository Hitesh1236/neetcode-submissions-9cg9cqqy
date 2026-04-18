class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n + 1);
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            int sum = carry;
            sum += digits[i];
            carry = sum / 10;
            ans[i + 1] = sum % 10;
        } 
        ans[0] = carry;
        if(ans[0] == 0){
            vector<int> newAns(ans.begin()+1,ans.end());
            return newAns;
        }
        return ans;
    }
};
