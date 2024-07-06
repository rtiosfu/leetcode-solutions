class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if(prices.size() == 1){
            return maxProfit;
        }
        int leftIndex = 0;
        int rightIndex = 1;
        //two ptr soln
        //left keeps track of the 'local' minimum, while the right keeps on going to find the largest diff
        while(rightIndex < prices.size()){
            int sellProfit = prices[rightIndex] - prices[leftIndex];
            if(sellProfit <= 0){
                leftIndex = rightIndex;
                rightIndex = leftIndex + 1;
            }else if(sellProfit <= maxProfit){
                rightIndex++;
            }else{
                maxProfit = sellProfit;
                rightIndex++;
            }
        }

        return maxProfit;
    }
};