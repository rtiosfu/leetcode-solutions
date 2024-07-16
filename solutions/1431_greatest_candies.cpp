class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        uint8_t maxCandies = *max_element(candies.begin(), candies.end());
        std::vector<bool> results(candies.size(), false);
        for(uint8_t i = 0; i < candies.size(); ++i){
            results[i] = candies[i] + extraCandies >= maxCandies;
        }
        return results;
    }
};