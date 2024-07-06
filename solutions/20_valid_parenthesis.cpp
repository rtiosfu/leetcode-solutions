class Solution {
public:

    bool isValid(string s) {
        stack<char> paren;  

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                paren.push(s[i]);
            }else{
                if(paren.empty()){
                    return false;
                }
                if(s[i] == ')' && paren.top() == '('){
                    paren.pop();
                }else if(s[i] == '}' && paren.top() == '{'){
                    paren.pop();
                }else if(s[i] == ']' && paren.top() == '['){
                    paren.pop();
                }else{
                    return false;
                }
            }
        }
        //there should be no braces left open
        return paren.empty();
    }
};