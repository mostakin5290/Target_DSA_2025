class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        ans[0]=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            ans[i+1] = ans[i]+nums[i+1];
        }
        return ans;
    }
};