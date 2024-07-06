class Solution {
public:
    string reverseWords(string s) {
        std::string reversed(s.size(), ' ');
        int firstNonSpaceIndex = s.size()-1;
        int reversedIndex = 0;
        while(s[firstNonSpaceIndex] == ' ' && firstNonSpaceIndex >= 0){
            firstNonSpaceIndex--;
        }
        for(int right = firstNonSpaceIndex; right >= 0;){
            int left = right;
            //move left ptr until it reaches the first character of the current word (or 0)
            while(left > 0 && s[left-1] != ' '){
                left--;
            }
            //fill word into reversed
            for(int i = left; i <= right; ++i){
                reversed[reversedIndex] = s[i];
                reversedIndex++;
            }
            reversed[reversedIndex] = ' ';
            reversedIndex++;
            right = left - 1;
            while(right >= 0 && s[right] == ' '){
                right--;
            }
        }
        while(reversed.size() > 0 && reversed[reversed.size()-1] == ' '){
            reversed.pop_back();
        }
        return reversed;
    }
};