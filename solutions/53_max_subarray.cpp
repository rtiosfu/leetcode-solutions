//use an array to track the maximum value of a subarray ending at index i.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> subarraySums(nums);
        for(int i = 1; i < nums.size(); ++i){
            subarraySums[i] = max(nums[i], nums[i] + subarraySums[i-1]);
        }
        return *max_element(subarraySums.begin(), subarraySums.end());
    }
};