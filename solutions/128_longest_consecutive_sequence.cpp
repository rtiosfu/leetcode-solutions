class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }else if (nums.size() == 1){
            return 1;
        }

        std::unordered_set<int> numSet(nums.begin(), nums.end()); 
        
        int longestSubseq = 1;

        for(int i = 0; i < nums.size(); ++i){
            if(numSet.find(nums[i]-1) == numSet.end()){
                int nextNum = nums[i]+1;
                int currentLength = 1;
                while(numSet.find(nextNum) != numSet.end()){
                    currentLength++;
                    longestSubseq = max(longestSubseq, currentLength);
                    nextNum++;
                }
            }
            
        }
        
        return longestSubseq;

    }
};