class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        vector<string> result = {};
        int intervalStart = nums[0];
        int intervalEnd = intervalStart;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != intervalEnd+1){
                if(intervalStart != intervalEnd){
                    result.push_back(to_string(intervalStart) + "->" + to_string(intervalEnd));
                }else{
                    result.push_back(to_string(intervalStart));
                }
                intervalStart = nums[i];
                intervalEnd = intervalStart;
            }else{
                intervalEnd = nums[i];
            }

        }
        if(intervalStart != intervalEnd){
            result.push_back(to_string(intervalStart) + "->" + to_string(intervalEnd));
        }else{
            result.push_back(to_string(intervalStart));
        }
        return result;
    }
};