class Solution {
public:

    int romanCharToInt(const char c){
        switch (c){
            case 'I':
            return 1;
            case 'V':
            return 5;
            case 'X':
            return 10;
            case 'L':
            return 50;
            case 'C':
            return 100;
            case 'D':
            return 500;
            case 'M':
            return 1000;
            default:
            return 0;
        }
    }

    int romanToInt(string s) {
        int sum = 0;
        if(s.size() == 1){
            return romanCharToInt(s[0]);
        }
        for(int i = 0; i < s.size(); ++i){
            //do the easy cases first
            if(s[i] == 'V'){
                sum += 5;
            }else if(s[i] == 'L'){
                sum += 50;
            }else if(s[i] == 'D'){
                sum += 500;
            }else if(s[i] == 'M'){
                sum += 1000;
            }else if(s[i] == 'I'){
                if(i + 1 < s.size() && s[i+1] == 'V' || s[i+1] == 'X'){
                    sum -= 1;
                }else{
                    sum += 1;
                }
            }else if(s[i] == 'X'){
                if(i + 1 < s.size() && s[i+1] == 'L' || s[i+1] == 'C'){
                    sum -= 10;
                }else{
                    sum += 10;
                }
            }else{//C
                if(i + 1 < s.size() && s[i+1] == 'D' || s[i+1] == 'M'){
                    sum -= 100;
                }else{
                    sum += 100;
                }
            }
        }
        return sum;
    }
};