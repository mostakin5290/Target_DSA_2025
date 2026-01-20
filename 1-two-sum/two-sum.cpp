class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int require = target - nums[i];
            if(mp.find(require) == mp.end()){
                mp[nums[i]]=i;
            }
            else{
                ans.push_back(mp[require]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};