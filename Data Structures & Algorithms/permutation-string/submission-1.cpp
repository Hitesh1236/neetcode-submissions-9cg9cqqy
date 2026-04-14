class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int> need(26,0);
        vector<int> window(26,0);
        for(int i = 0; i < m; i++){
            need[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
        if(need == window) return true;
        if(m == n) return false;
        for(int i = 1; i < n - m + 1; i++){
            window[s2[i - 1] - 'a']--;
            window[s2[i + m - 1] - 'a']++;
            if(window == need) return true;
        }
        return false;
    }
};
