class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size() - 1;
        int u = 0;
        int d = matrix.size() - 1;
        vector<int> ans;
        while(l < r && u < d){
            // up
            for(int i = l; i < r; i++){
                ans.push_back(matrix[u][i]);
            }
            // right
            for(int i = u; i < d; i++){
                ans.push_back(matrix[i][r]);
            }
            // down
            for(int i = r; i > l; i--){
                ans.push_back(matrix[d][i]);
            }
            // left
            for(int i = d; i > u; i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
            r--;
            u++;
            d--;
        }
        if(l==r && u==d){
            ans.push_back(matrix[u][l]);
        }
        if(u==d && l < r){
            for(int i = l; i <= r; i++){
                ans.push_back(matrix[u][i]);
            }
        }
        if(l==r && u < d){
            for(int i = u; i <= d; i++){
                ans.push_back(matrix[i][l]);
            }
        }
        return ans;
    }
};
