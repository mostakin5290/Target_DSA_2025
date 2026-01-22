class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j=0;
        while(i!=n){
            if(nums[i]==0) i++;
            else if(nums[i]!=0 && nums[j]==0){
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
                i++;
            }
            else if(nums[i]!=0 && nums[j]!=0){
                i++;
                j++;
            }
            else i++;
            

        }
    }
};