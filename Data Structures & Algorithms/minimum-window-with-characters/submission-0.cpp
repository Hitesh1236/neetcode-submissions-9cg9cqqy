class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t) need[c]++;

        int required = t.size();
        int formed = 0;

        int l = 0;
        int bestLen = INT_MAX;
        int bestL = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (window[c] <= need[c]) {
                formed++;
            }

            while (formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }

                window[s[l]]--;
                if (window[s[l]] < need[s[l]]) {
                    formed--;
                }
                l++;
            }
        }

        return (bestLen == INT_MAX) ? "" : s.substr(bestL, bestLen);
    }
};