class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 2){
            return min(height[0], height[1]);
        }
        int left = 0;
        int right = height.size() - 1;
        int maxSoFar = min(height[left], height[right]) * right;
        while(right > left){
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
            maxSoFar = max(maxSoFar, min(height[left], height[right]) * (right - left));
        }
        return maxSoFar;
    }
};