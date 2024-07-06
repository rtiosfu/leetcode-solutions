class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastCharIndex = s.size()-1;
        while(s[lastCharIndex] == ' ' && lastCharIndex >= 0){
            lastCharIndex--;
        }
        int length = 0;
        for(int i = lastCharIndex; i >= 0; --i){
            if(s[i] == ' '){
                return length;
            }else{
                length++;
            }
        }
        return length;
    }
};