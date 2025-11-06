class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int dup_x = x;
        int rev = 0;

        while(x>0){
            int temp = x%10;
            if(rev>INT_MAX/10 || rev<INT_MIN/10)return false;
            rev = (rev*10) + temp;
            x = x/10;
        }

        return dup_x == rev;
    }
};