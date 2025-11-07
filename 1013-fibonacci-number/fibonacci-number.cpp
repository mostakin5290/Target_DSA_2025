class Solution {
public:
    int fib(int n) {
       if(n==0)return 0;
       if(n==1)return 1;
       int ans = 1;
       int prev = 0;

       for(int i = 1 ; i < n ; i++) {
        int temp = ans;
        ans+=prev;
        prev=temp;
       }

       return ans;
    }
};