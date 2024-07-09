class Solution {
public:
//the main intuition here is that there is a 2 way relationship that needs to be maintained 
//between a pattern letter and a word from string. 
//therefore, we require two tables (hashmaps, in this case) in order to check 'both ways'
//with every word that we find.
    bool wordPattern(string pattern, string s) {
        //associate strings with chars
        std::unordered_map<std::string, char> wordTable;
        //associate chars with strings
        std::unordered_map<char, std::string> charTable;

        std::string currentWord = "";
        uint16_t patternIndex = 0;
        for(uint16_t i = 0; i <= s.size(); ++i){
            if((i == s.size() || s[i] == ' ') && currentWord.size() > 0){
                auto charSearch = charTable.find(pattern[patternIndex]);
                auto wordSearch = wordTable.find(currentWord);
                if(charSearch == charTable.end() && wordSearch == wordTable.end()){
                    //neither the character or the word is associated with anything
                    wordTable.insert({currentWord, pattern[patternIndex]});
                    charTable.insert({pattern[patternIndex], currentWord});
                }else if(charSearch != charTable.end() && wordSearch != wordTable.end()){
                    if(currentWord.compare(charSearch->second)){
                        return false;
                    }
                }else{
                    //if only one table returns something, then that means that 
                    //either the character has already been associated 
                    //or the word has already been associated but not the other.
                    //therefore, the word pattern must not match.
                    return false;
                }
                currentWord = "";
                patternIndex++;
            }else{
                currentWord += s[i];
            }
        }
        return patternIndex == pattern.size();
    }
};