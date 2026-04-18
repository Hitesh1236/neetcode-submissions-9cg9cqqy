class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int x = i;
            int res = 0;
            while(x){
                if(x & 1){
                    res++;
                }
                x >>= 1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
