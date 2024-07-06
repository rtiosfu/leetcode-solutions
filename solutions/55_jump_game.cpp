class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int maxReached = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(i > maxReached){
                return false;
            }
            maxReached = max(maxReached, i+nums[i]);
            if(maxReached >= nums.size()-1){
                return true;
            }
        }
        return false;
    }
};