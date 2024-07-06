class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(), 1); 
        std::vector<int> prefix(nums.size(), 1);
        std::vector<int> suffix(nums.size(), 1);
        const int vectorEndIndex = nums.size() - 1;
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[vectorEndIndex - i] = suffix[vectorEndIndex - i + 1] * nums[vectorEndIndex - i + 1];
        }

        for(int i = 0; i < nums.size(); i++){
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};