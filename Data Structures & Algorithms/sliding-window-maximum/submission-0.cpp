class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.front()] <= nums[i]){
                dq.pop_front();
            }
            dq.push_front(i);
        }
        ans.push_back(nums[dq.back()]);
        for(int i = 1; i < n - k + 1; i++){
            int l = i;
            int r = i + k - 1;
            while(!dq.empty() && nums[dq.front()] <= nums[r]){
                dq.pop_front();
            }
            dq.push_front(r);
            while(!dq.empty() && dq.back() < l){
                dq.pop_back();
            }
            ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};
