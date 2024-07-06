class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        vector<int> longestSubseq(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    longestSubseq[i] = max(longestSubseq[i], longestSubseq[j]+1);
                }
            }
        }
        return *max_element(longestSubseq.begin(), longestSubseq.end());
    }
};