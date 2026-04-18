class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int sum = (a & 1)^(b & 1)^(carry & 1);
            carry = ((a & 1) & (b & 1)) | ((a & 1) & (carry & 1)) | ((carry & 1) & (b & 1));
            a >>= 1;
            b >>= 1;
            ans = (sum << i) | ans;
        }
        return ans;
    }
};
