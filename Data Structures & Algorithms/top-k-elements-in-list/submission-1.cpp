class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            map[nums[i]]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto& it:map){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = n; i > 0; i--){
            for(int x:bucket[i]){
                ans.push_back(x);
                k--;
                if(k == 0) return ans;
            }
        }
        return {};
    }
};
