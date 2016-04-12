class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // use dp
        int size = s.size();
        if(size == 0) return true;
        bool reg[size+1];
        memset(reg, 0, sizeof(reg));
        reg[0] = true;
        for(int i = 1; i <= size; i++){
            for(int j = 0; j < size; j++){
                if(reg[j] && dictContains(s.substr(j, i-j), dict)){
                    reg[i] = true;
                    break;
                }
            }
        }
        return reg[size];
    }
    
    bool dictContains(string s, unordered_set<string> &dict){
        return dict.find(s) != dict.end();
    }
};