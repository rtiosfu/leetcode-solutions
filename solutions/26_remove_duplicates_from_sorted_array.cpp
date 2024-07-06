class Solution {
public:
    //this solution takes advantage of the fact that 
    //we're really only trying to get the n distinct elements into the first
    //n spaces in the array. So we can use a pointer to the next place in the array for 
    //the distinct elements while iterating over the rest in search of the distinct ones.
    int removeDuplicates(vector<int>& nums) {
        uint16_t fillIndex = 1;
        int16_t currentElement = nums[0];
        uint16_t distinctElements = 1;
        for(uint16_t i = 1; i < nums.size(); ++i){
            if(nums[i] != currentElement){
                nums[fillIndex] = nums[i];
                fillIndex++;
                currentElement = nums[i];
                distinctElements++;
            }
        }
        return distinctElements;
    }
};