class Solution {
public:
    int climbStairs(int n) {

        vector<int> counts(n+1, 0);
        counts[0] = 1;
        counts[1] = 2;

        for(int i = 2; i < n; i++){
            counts[i] = counts[i-1] + counts[i-2];
        }

        return counts[n-1];
    }
};