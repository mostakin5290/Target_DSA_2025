class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceSoFar = prices[0];
        int maxProfit = 0;

        for(int i=0;i<prices.size();i++){
            int Profit = prices[i] - minPriceSoFar; 
            if(Profit>maxProfit) maxProfit = Profit;
            if(minPriceSoFar>prices[i])minPriceSoFar=prices[i];

        }
        return maxProfit;
    }
};