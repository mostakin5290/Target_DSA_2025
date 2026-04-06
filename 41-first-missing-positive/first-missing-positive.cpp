class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n,false);

        for(int i = 0; i<n;i++){
            if(nums[i]<=n && nums[i]>0){
                v[nums[i]-1] = true;
            }
        }

        for(int i = 0; i<n;i++){
            if(v[i]==false){
                return i+1;
            }
        }

        return n+1;

    }
};