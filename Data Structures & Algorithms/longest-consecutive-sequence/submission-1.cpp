class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0) return 0;
        map[nums[0]] = 1;
        for(int i = 1; i < n; i++){
            if(map.find(nums[i] - 1)!=map.end()){
                map[nums[i]] = map[nums[i] - 1] + 1;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        int maxi = 1;
        for(auto& it:map){
            maxi = max(maxi,it.second);
        }
        return maxi;
    }
};
