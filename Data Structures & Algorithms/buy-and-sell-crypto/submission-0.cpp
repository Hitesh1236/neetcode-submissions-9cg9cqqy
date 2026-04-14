class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastMin = prices[0];
        int maxi = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++){
            lastMin = min(lastMin,prices[i]);
            maxi = max(maxi,prices[i] - lastMin);
        }
        return maxi;
    }
};
