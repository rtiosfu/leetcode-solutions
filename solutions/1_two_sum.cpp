class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        if(nums.size() == 2 && nums[0] + nums[1] == target){
            return {0, 1};
        }else if (nums.size() == 2){
            return {};
        }

        for(int i = 0; i < nums.size(); i++){
            numMap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(numMap.count(complement) && numMap[complement] != i){
                return {i, numMap[complement]};
            }
        }
        return {};
    }
};