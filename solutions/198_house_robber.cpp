class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        //use an array to track the maximum value found so far
        vector<int> totals(nums.size(), 0);
        totals[0] = nums[0];
        totals[1] = nums[0] > nums[1] ? nums[0] : nums[1];

        for(int i = 2; i < nums.size(); ++i){ 
            totals[i] = max(totals[i-2] + nums[i], totals[i-1]);
        }
        return totals[nums.size()-1];


    }
};