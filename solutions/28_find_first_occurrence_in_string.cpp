class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()){
            return -1;
        }
        for(int i = 0; i <= haystack.size() - needle.size(); i++){
            if(haystack[i] != needle[0]){
                continue;
            }
            bool doesSubstringMatch = true;
            for(int j = 1; j < needle.size(); j++){
                doesSubstringMatch = haystack[i+j] == needle[j];
                if(!doesSubstringMatch){
                    break;
                }
            }
            if(doesSubstringMatch){
                return i;
            }
        }
        return -1;
    }
};