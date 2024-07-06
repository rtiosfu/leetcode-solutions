class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> summands = {0, 0};
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;
        int currentSum = numbers[leftIndex] + numbers[rightIndex];
        while(currentSum != target){
            if(currentSum < target){
                leftIndex++;
                //rightIndex = numbers.size()-1;
            }
            if(currentSum > target){
                rightIndex--;
                //leftIndex = 0;
            }
            currentSum = numbers[leftIndex] + numbers[rightIndex];
        }
        summands[0] = leftIndex+1;
        summands[1] = rightIndex+1;
        return summands;
    }
};