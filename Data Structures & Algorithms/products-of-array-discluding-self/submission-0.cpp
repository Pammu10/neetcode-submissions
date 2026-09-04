class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 0);
        vector<int> suff(nums.size(), 0);
        pre[0] = nums[0];
        suff[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++){
            pre[i] = pre[i-1] * nums[i];
            suff[nums.size() - i - 1] = suff[nums.size() - i] * nums[nums.size() - i - 1];
        }
        vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++){
            if (i > 0) ans[i] *= pre[i-1];
            if (i < nums.size() - 1) ans[i] *= suff[i + 1];
        }
        return ans;
    }
};
