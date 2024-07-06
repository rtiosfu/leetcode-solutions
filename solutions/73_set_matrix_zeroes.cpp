class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return;
        }
        bool isFirstRowZero = false;
        for(int n = 0; n < matrix[0].size(); ++n){
            if(matrix[0][n] == 0){
                isFirstRowZero = true;
                break;
            }
        }
        //start at 1 so that we can use the first row as notation
        //for which columns have a 0 inside. Can then immediately fill other rows with 0s
        //if they are ever found.
        for(int m = 1; m < matrix.size(); ++m){
            bool foundZero = false;

            for(int n = 0; n < matrix[0].size(); ++n){
                //require to iterate over every 0 in case there is a 0 at the end
                if(matrix[m][n] == 0){
                    matrix[0][n] = 0;
                    foundZero = true;
                }
            }
            if(foundZero){
                memset(&matrix[m][0], 0, matrix[m].size() * sizeof(matrix[m][0]));
            }
        }
        for(int n = 0; n < matrix[0].size(); ++n){
            if(matrix[0][n] == 0){
                for(int m = 1; m < matrix.size(); ++m){
                    matrix[m][n] = 0;
                }
            }
        }
        if(isFirstRowZero){
            memset(&matrix[0][0], 0, matrix[0].size() * sizeof(matrix[0][0]));
        }
    }
};