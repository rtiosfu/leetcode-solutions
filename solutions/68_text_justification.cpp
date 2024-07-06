class Solution {
public:

    static std::string justifyLine(const vector<string>& words, const int maxWidth, const int spaceCount){
        std::string line(maxWidth, ' ');
        const uint8_t wordCount = words.size();
        if(wordCount == 1){
            memcpy(&line[0], &words[0][0], words[0].size());
        }else if(spaceCount % (wordCount - 1) == 0){
            //evenly distributed spaces
            uint8_t nextIndex = 0;
            uint8_t spacesLeft = spaceCount;
            const uint8_t spacesPerWord = spaceCount / (wordCount - 1);
            for(int i = 0; i < wordCount; ++i){
                const uint8_t wordLength = words[i].size();
                memcpy(&line[nextIndex], &words[i][0], wordLength);
                nextIndex += wordLength + spacesPerWord;
            }
        }else{
           uint8_t nextIndex = 0;
           uint8_t spacesLeft = spaceCount;
           const uint8_t spacesPerWord = spaceCount / (wordCount - 1);
           uint8_t extraSpaces = spaceCount % (wordCount - 1);
           for(int i = 0; i < wordCount; ++i){
                const uint8_t wordLength = words[i].size();
                memcpy(&line[nextIndex], &words[i][0], wordLength);
                nextIndex += wordLength + spacesPerWord;
                if(extraSpaces > 0){
                    nextIndex++; 
                    extraSpaces--;
                }
                
           }
        }
        return line;
    }

    static std::string justifyFinalLine(const vector<string>& words, const int maxWidth){
        std::string finalLine(maxWidth, ' ');
        uint8_t nextIndex = 0;
        for(int i = 0; i < words.size(); ++i){
            memcpy(&finalLine[nextIndex], &words[i][0], words[i].size());
            nextIndex += words[i].size() + 1;
        }
        return finalLine;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<string> justifiedText = {};
        uint8_t currentLength = 0;
        uint8_t charCount = 0;
        //uint8_t wordCountForCurrentLine = 0;
        std::vector<std::string> lineWords = {};
        for(int i = 0; i < words.size(); ++i){
            currentLength += words[i].size();
            charCount += words[i].size();
            lineWords.push_back(words[i]);
            if(currentLength >= maxWidth){
                if(currentLength > maxWidth){
                    //'undo' the addition of the next word, because it will 
                    //go over the alloted width
                    lineWords.pop_back();
                    currentLength -= words[i].size();
                    charCount -= words[i].size();
                    i--;
                }
                //justify
                justifiedText.push_back(justifyLine(lineWords, maxWidth, maxWidth - charCount));
                lineWords = {};
                currentLength = 0;
                charCount = 0;
            }else if(i == words.size()-1){
                //manually justify here
                justifiedText.push_back(justifyFinalLine(lineWords, maxWidth));
                lineWords = {};
            }else{
                //add a space to length
                currentLength++;
            }
        }
        return justifiedText;
    }
};