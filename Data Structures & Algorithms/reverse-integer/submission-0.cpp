class Solution {
public:
    int reverse(int x) {
        bool isNeg = (x < 0) ? true : false;
        int m = abs(x);
        int ans = 0;
        while(m){
            int digit =m % 10;
            m /= 10;
            if(!isNeg && ((ans > (INT_MAX / 10))||((ans == (INT_MAX / 10))&(digit > 7)))) return 0;
            if(isNeg && ((ans > (INT_MAX / 10))||((ans == (INT_MAX / 10))&(digit > 8)))) return 0;
            ans = ans * 10 + digit;
        }
        if(isNeg) return -ans;
        return ans;
    }
};
