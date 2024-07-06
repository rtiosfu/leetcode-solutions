class Solution {
public:

    static inline void swap(vector<int>& nums, const uint8_t left, const uint8_t right){
        const int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }else if(nums.size() == 1){
            return nums[0] == val ? 0 : 1;
        }
        int16_t leftIndex = 0;
        int16_t rightIndex = nums.size() - 1;
        uint8_t totalValues = 0;
        
        while(rightIndex >= 0 && nums[rightIndex] == val){
            rightIndex--;
            totalValues++;
        }

        for(leftIndex; leftIndex < rightIndex; ++leftIndex){
            if(nums[leftIndex] == val){
                swap(nums, leftIndex, rightIndex);
                while(rightIndex >= 0 && nums[rightIndex] == val){
                    rightIndex--;
                    totalValues++;
                }
            }
        }
        return nums.size() - totalValues;
    }
};