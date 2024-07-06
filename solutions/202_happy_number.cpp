class Solution {
public:

    inline unsigned int getNextNumber(int n){
        unsigned int nextNum = 0;
        while(n){
            nextNum += (n % 10) * (n % 10);
            n /= 10;
        }
        return nextNum;
    }

    bool isHappy(int n) {
        if(n == 1){
            return true;
        }

        std::unordered_set<int> prevNumbers;
        prevNumbers.insert(n);
        bool cycleFound = false;
        unsigned int nextNum = n;
        while(!cycleFound){
            nextNum = getNextNumber(nextNum);
            if(nextNum == 1){
                return true;
            }
            auto insertion = prevNumbers.insert(nextNum);
            if(!insertion.second){
                return false;
            }
        }
        return false;
        
    }
};