class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        uint16_t magazineChars[26];
        for(const char c : magazine){
            magazineChars[c-'a']++;
        }

        for(const char c : ransomNote){
            if(magazineChars[c-'a'] == 0){
                return false;
            }else{
                magazineChars[c-'a']--;
            }
        }
        return true;
    }
};