//this problem approaches the solution using a hashtable 
//that differentiates between strings via their length.
//Using this hashtable, the searchspace can be narrowed down 
//only to strings that are possibly magical to the search
//string. 
//Outside of some clever way of comparing strings, 
//I don't see any way that you can get out of simply 
//comparing all of the letters in each candidate word.
//Therefore, it is required to trim the searchspace for a particular 
//word down as much as possible.
//The unordered_set is included to make insertion operations O(1) 
//operations rather than O(n).
class MagicDictionary {
private:
    unordered_map<uint8_t, std::vector<std::string>> lengthDict;
    unordered_set<std::string> stringDict;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(const std::string& s : dictionary){
            stringDict.insert(s);
            auto search = lengthDict.find(s.size());
            if(search != lengthDict.end()){
                lengthDict[s.size()].push_back(s);
            }else{
                lengthDict[s.size()] = {s};
            }
        }
    }
    
    bool search(string searchWord) {
        auto search = lengthDict.find(searchWord.size());
        if(search != lengthDict.end()){
            for(const std::string& s : search->second){
                uint8_t differentLetters = 0;
                for(uint8_t i = 0; i < s.size(); ++i){
                    differentLetters += s[i] != searchWord[i];
                    if(differentLetters > 1){
                        break;
                    }
                }
                if(differentLetters == 1){
                    return true;
                }
            }
        }
        
        return false;
    }
};