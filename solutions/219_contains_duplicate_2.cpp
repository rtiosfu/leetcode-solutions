class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0){
            return false;
        }
        if(k == 1){
            for(int i = 0; i < nums.size()-1; ++i){
                if(nums[i] == nums[i+1]){
                    return true;
                }
            }
            return false;
        }
        if(k >= nums.size()){
            unordered_set<int> values;
            for(int i = 0; i < nums.size(); ++i){
                if(!values.insert(nums[i]).second){
                    return true;
                }
            }
            return false;
        }

        unordered_set<int> values;

        //manually fill the first window
        for(int j = 0; j <= k && j < nums.size(); ++j){
            if(!values.insert(nums[j]).second){
                return true;
            }
        }
        values.erase(nums[0]);

        for(int i = 1; i < nums.size()-k; ++i){
            cout << i << '\n';
            if(i+k < nums.size() && !values.insert(nums[i+k]).second){
                return true;
            }
            values.erase(nums[i]);
        }
        return false;
    }
};