class Solution {
public:
    void Rotate_temp(vector<int>& arr,int i , int j){
        while(i<j){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(!k)return;

        Rotate_temp(nums,0,n-1);
        Rotate_temp(nums,0,k-1);
        Rotate_temp(nums,k,n-1);
    }
};