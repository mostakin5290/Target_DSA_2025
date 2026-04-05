class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>un;
        vector<int>ans;
        int n = nums.size();

        for(int i = 0;i<n;i++ ){
            if(un.find(nums[i])==un.end()){
                un[nums[i]]=1;
            }

            else{
                un[nums[i]]++;
            }
        }

        for(const auto& i:un ){
            if(i.second>n/3) ans.push_back(i.first);
        }

        sort(ans.begin(),ans.end());

        return ans;


    }
};