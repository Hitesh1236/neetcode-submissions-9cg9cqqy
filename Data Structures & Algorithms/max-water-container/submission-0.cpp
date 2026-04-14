class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int ans = (r - l) * (min(heights[l],heights[r]));
            maxi = max(maxi,ans);
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};
