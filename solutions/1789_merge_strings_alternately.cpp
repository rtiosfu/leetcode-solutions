class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.size() == 0){
            return word2;
        }else if(word2.size() == 0){
            return word1;
        }
        std::string mixedWord = "";

        uint8_t charIndex = 0;
        for(const char& c : word1){
            mixedWord += c;
            mixedWord += word2[charIndex];
            charIndex++;
            if(charIndex > word2.size() - 1){
                break;
            }
        }
        for(uint8_t i = charIndex; i < word1.size(); ++i){
            mixedWord += word1[i];
        }
        for(uint8_t i = charIndex; i < word2.size(); ++i){
            mixedWord += word2[i];
        }
        return mixedWord;
        
    }
};