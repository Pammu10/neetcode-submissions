class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> suff(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            pre[i] = pre[i-1] * nums[i-1];
            suff[nums.size() - i - 1] = suff[nums.size() - i] * nums[nums.size() - i];
        }
        vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++){
            ans[i] = pre[i] * suff[i];
        }
        return ans;
    }
};
