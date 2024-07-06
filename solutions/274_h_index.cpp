class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0){
            return 0;
        }else if(citations.size() == 1){
            return citations[0] >= 1;
        }
        std::sort(citations.begin(), citations.end());
        int max_h = citations.size();
        for(int i = 0; i < citations.size(); ++i){
            if(citations[i] >= max_h){
                return max_h;
            }else{
                max_h--;
            }
        }
        return max_h;
    }
};