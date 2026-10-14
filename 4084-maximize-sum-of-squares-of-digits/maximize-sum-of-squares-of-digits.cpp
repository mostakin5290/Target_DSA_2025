class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(sum){
            if(sum>=9){
                sum -=9;
                ans +='9';
            }
            else{
                ans += std::to_string(sum);
                sum -=sum;
            }
        }

        int n = ans.length();
        if(num<n) return "";
        if(num!=n){
            int temp = num - n ;
            cout<<temp;
            while(temp>0) {
                ans+='0';
                temp --;
            }
        }

        return ans;

    }
};