class Solution {
public:
    int smallestNumber(int n) {
        int x=1;
        int ans=1;
        if(n==1)return 1;
        while(n>=x){
            x=x*2;
            ans = x-1;
            };
        return ans;
    }
};