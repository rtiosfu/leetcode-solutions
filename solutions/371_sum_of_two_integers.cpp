class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        bool carry = false;
        for(int i = 0; i < (sizeof(int) * 8); i++){
            int mask = 1 << i;
            bool firstNumBit = !(a & mask) == 0;
            bool secondNumBit = !(b & mask) == 0;
            bool isBothOne = firstNumBit && secondNumBit;
            if(isBothOne){
                //carry over a bit
                if(carry){
                    //set a specific bit in the result to 1
                    result |= mask;
                }else{
                    carry = true;
                }
            }else{
                if(firstNumBit || secondNumBit){
                    //if carry is true, then it is the same case as both being one
                    //carry will stay true in the next iteration of the loop
                    if(!carry){
                        result |= mask;
                    }
                }else{
                    if(carry){
                        result |= mask;
                        carry = false;
                    }
                }
            }
        }
        return result;
    }
};