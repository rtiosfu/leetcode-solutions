class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if(tasks.size() == 1){
            return -1;
        }

        unordered_map<int, int> taskCount; 

        int totalRoundsRequired = 0;
        for(int task : tasks){
            if(taskCount.find(task) == taskCount.end()){
                taskCount[task] = 1;
            }else{
                taskCount[task]++;
            }
        }

        for(auto it = taskCount.begin(); it != taskCount.end(); it++){

            //task sizes of 1 are impossible to solve
            if(it->second == 1){
                return -1;
            }
            if(it->second % 3 == 0){
                totalRoundsRequired += it->second / 3;
            }else{
                //case: count % 3 == 1, then break the final four into 
                //2, take away one from the three and add 2 rounds
                //case: count count % 3 == 2, then take as many as possible
                //before completing the final 2
                //either way, it will result in the same number of total tasks.
                totalRoundsRequired += (it->second / 3) + 1;
            }
        }
        return totalRoundsRequired;
    }
};