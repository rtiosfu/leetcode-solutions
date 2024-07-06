class Solution {
public:
    bool isSubsequence(string s, string t) {
        uint8_t s_index = 0;

        if(s.size() == 0){
            return true;
        }else if(t.size() == 0){
            return false;
        }

        for(char c : t){
            if(s_index < s.size() && c == s[s_index]){
                s_index++;
            }
        }

        return s_index == s.size();

    }
};