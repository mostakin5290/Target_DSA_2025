class Solution {
public:
    int makeTheIntegerZero(long long int num1,long long int num2) {
        for(int i=1;i<=32;i++){
            if(num1<=num2){
                return -1;
            }else{
                num1-=num2;
                int sum=0;
                long long l=num1;
                while(l>0){
                    sum+=l%2;
                    l=l/2;
                }
                cout<<sum<<endl;
                if(sum<=i && num1>=i){
                    return i;
                }
            }
        }
        return -1;
    }
};