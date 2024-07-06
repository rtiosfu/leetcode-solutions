class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t mask = 1;
        #define size sizeof(uint32_t) * 8

        for(int i = 0; i < size/2; ++i){
            result |= (n & mask) << (size - (2*i) - 1);
            mask = mask << 1;
        }

        mask = 1 << (size - 1);

        for(int i = 0; i < size/2; ++i){
            result |= (n & mask) >> (size - (2*i) - 1);
            mask = mask >> 1;
        }

        return result;

    }
};