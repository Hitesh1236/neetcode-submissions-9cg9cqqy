class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.length();
        if(n == 0) return 0;
        vector<int> window(256,0);
        int count = 0;
        int maxi = 0;
        while(r < n){
            while(r < n && count == r - l){
                if(window[s[r]]==0){
                    count++;
                }
                window[s[r]]++;
                if(count == r - l + 1) maxi = max(maxi,r - l + 1);
                r++;
            }
            window[s[l]]--;
            if(window[s[l]]==0) count--;
            l++;
        }
        return maxi;
    }
};
