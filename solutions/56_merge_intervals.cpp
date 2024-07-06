class Solution {
public:

    inline bool isInInterval(const int left, const int right, const int test){
        return (left <= test) && (test <= right);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> result = {};
        int leftLimit = intervals[0][0];
        int rightLimit = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int currentLeftLimit = intervals[i][0];
            int currentRightLimit = intervals[i][1];
            //the next interval is past the right
            if(currentLeftLimit > rightLimit){
                result.push_back({leftLimit, rightLimit});
                leftLimit = currentLeftLimit;
                rightLimit = currentRightLimit;
            }else if(currentRightLimit > rightLimit){//currentLeftLimit <= rightLimit
                rightLimit = currentRightLimit;
            }
        }
        result.push_back({leftLimit, rightLimit});
        return result;
    }
};