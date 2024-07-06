class Solution {
public:
    int hammingWeight(int n) {
        int oneBits = 0;
        for(int i = 0; i < (sizeof(int) * 8); ++i){
            if(((1 << i) & n)){
                ++oneBits;
            }
        }
        return oneBits;
    }
};