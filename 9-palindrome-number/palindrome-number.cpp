class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;

        string str_x = to_string(x);
        int start=0;
        int end = str_x.length()-1;

        while(start<end){
            if(str_x[start]==str_x[end]){
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};