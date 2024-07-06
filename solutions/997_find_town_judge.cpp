class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1){
            return 1;
        }
        std::vector<uint16_t> howManyTrustN(n+1, 0);
        std::vector<uint16_t> howManyNTrusts(n+1, 0);

        for(int i = 0; i < trust.size(); ++i){
            howManyTrustN[trust[i][1]]++;
            howManyNTrusts[trust[i][0]]++;
        }
        for(int i = 0; i < howManyTrustN.size(); ++i){
            if(howManyTrustN[i] == n-1 && howManyNTrusts[i] == 0){
                return i;
            }
        }
        return -1;

    }
};