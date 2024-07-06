class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        //count min number of ways to get to a value, 0 = no found way
        vector<int> counts(amount, 0);
        int minCoin = coins[0];
        for(int coin : coins){
            if(coin == amount){
                return 1;
            }
            if(coin < amount){
                counts[coin-1] = 1;
            }
            minCoin = min(minCoin, coin);
        }

        for(int i = minCoin-1; i < amount; i++){
            //values of 0 in counts mean there are no ways to get there with the given
            //coins, so ignore them.
            if(counts[i] > 0){
                for(int coin : coins){
                    if(coin < amount && i+coin < amount){
                        //only increment count if there
                        //is no known way to reach it or 
                        //if this way results in less.
                        if(counts[i+coin] > counts[i] + 1 || counts[i+coin] == 0){
                            counts[i+coin] = counts[i] + 1;
                        }
                    }
                }
            }
        }
        return counts[amount-1] > 0 ? counts[amount-1] : -1;
    }
};