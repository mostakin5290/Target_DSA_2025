class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            ans.push_back(std::abs(num));
        }


        sort(ans.begin(), ans.end());
        for(int i = 0; i<nums.size();i++){
            ans[i] *= ans[i];
        }

        return ans;
    }
};