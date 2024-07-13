class Solution {
public:
    bool judgeCircle(const string& moves) {
        int32_t horizontalDisplacement = 0;
        int32_t verticalDisplacement = 0;
        for(const char& move : moves){
            if(move == 'U'){
                verticalDisplacement++;
            }else if(move == 'D'){
                verticalDisplacement--;
            }else if(move == 'R'){
                horizontalDisplacement++;
            }else{
                horizontalDisplacement--;
            }
        }
        return horizontalDisplacement == 0 && verticalDisplacement == 0;
    }
};