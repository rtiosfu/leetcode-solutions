class Solution {
public:
    
    int jump(vector<int>& nums) {
        int32_t maxIndexReached = 0;
        vector<int> jumpCounts(nums.size(), 0);
        for(int i = 0; i < nums.size()-1; ++i){
            const int32_t distanceToMaxIndexReached = maxIndexReached - i;
            for(int j = 0; j < nums[i]-distanceToMaxIndexReached; ++j){
                if(maxIndexReached < nums.size()-1){
                    jumpCounts[maxIndexReached+1] = jumpCounts[i] + 1;
                    maxIndexReached++;
                }
                if(maxIndexReached == nums.size()-1){
                    return jumpCounts[nums.size()-1];
                }
            }
        }
        return jumpCounts[nums.size()-1];
    }
};