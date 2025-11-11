class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        // cout<<n;
        // vector <int> ans(2);
        int j=n-1;
        for(int i = 0; i < j;){
            // for(int j = i+1; j < n; j++){
            //     if(numbers[i]+numbers[j] == target) {
            //         // cout<<numbers[i]+numbers[j]<<" ";
            //         ans[0]=(i+1);
            //         ans[1]=(j+1);
            //         return ans;
            //     } 
            // }
            int sum = numbers[i]+numbers[j];

            if(sum==target) return {i+1,j+1};

            else if(sum > target) j--;

            else i++;
            

        }
        return {};
    }
};