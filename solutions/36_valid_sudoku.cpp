class Solution {
public:
    //returns the given sudoku box number (minus one) 
    //given a row and column.
    inline int8_t boxIndex(const int8_t row, const int8_t col){
        return (row / 3) * 3 + (col / 3);

    }

    inline int8_t charToNum(const char c){
        if(c == '.'){
            return -1;
        }else{
            return c - '1';
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //use an array indexed from 0 to 9 to count
        const uint8_t initSize = 9;

        std::vector<std::vector<bool>> rows(initSize, std::vector<bool>(initSize, false));
        std::vector<std::vector<bool>> cols(initSize, std::vector<bool>(initSize, false));
        std::vector<std::vector<bool>> boxes(initSize, std::vector<bool>(initSize, false));

        for(int m = 0; m < initSize; ++m){
            for(int n = 0; n < initSize; ++n){
                int16_t num = charToNum(board[m][n]);
                if(num >= 0){
                    if(rows[m][num] || cols[n][num] || boxes[boxIndex(m, n)][num]){
                        return false;
                    }else{
                        rows[m][num] = true;
                        cols[n][num] = true;
                        boxes[boxIndex(m, n)][num] = true;
                    }
                }
            }
        }
        
        return true;
    }
};