class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1){
            if(set.find(n)!=set.end()){
                return false;
            }
            set.insert(n);
            int m = n;
            n = 0;
            while(m){
                int digit = m % 10;
                n += digit * digit;
                m /= 10;
            }
        }
        return true;
    }
};
