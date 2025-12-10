class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = 10000000;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int k = 0;k<n-2;k++){
            int i = k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[k]+nums[i]+nums[j];
                if(abs(target-closestSum)>abs(target-sum)) closestSum = sum;
                if(sum > target) j--;
                else i++;
            }
        }

        return closestSum;
        
    }
};