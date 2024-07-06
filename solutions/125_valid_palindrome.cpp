class Solution {
public:

    bool isPalindrome(string s) {
        if(s.size() <= 1){
            return true;
        }
        int leftIndex = 0;
        int rightIndex = s.size() - 1;
        
        while(rightIndex > leftIndex){
            if(!isalnum(s[leftIndex])){
                leftIndex++;
                continue;
            }
            if(!isalnum(s[rightIndex])){
                rightIndex--;
                continue;
            }
            if(tolower(s[leftIndex]) != tolower(s[rightIndex])){
                return false;
            }else{
                leftIndex++;
                rightIndex--;
            }
        }
        return true;
    }
};