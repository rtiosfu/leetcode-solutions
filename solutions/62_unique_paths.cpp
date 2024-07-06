class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == n && m == 1){
            return 1;
        }
        std::vector<std::vector<int>> pathCounts(m, std::vector<int>(n, 0));
        pathCounts[0][0] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(j < n-1){
                    pathCounts[i][j+1] += pathCounts[i][j];
                }
                if(i < m-1){
                    pathCounts[i+1][j] += pathCounts[i][j];
                }
            }
        }
        return pathCounts[m-1][n-1];
    }
};