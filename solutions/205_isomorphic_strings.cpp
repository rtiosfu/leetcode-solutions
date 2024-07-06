class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        char mappings[256];
        memset(&mappings, '\0', sizeof(mappings[0]) * 256);
        bool usedChars[256];
        memset(&usedChars, false, sizeof(usedChars[0]) * 256);

        for(int i = 0; i < s.size(); ++i){
            if(mappings[t[i]] == '\0'){
                if(usedChars[s[i]]){
                    return false;
                }else{
                    mappings[t[i]] = s[i];
                    usedChars[s[i]] = true;
                }
            }
            t[i] = mappings[t[i]];
        }
        return !s.compare(t);
    }
};