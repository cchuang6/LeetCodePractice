class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        array<char, 128> s_map {0};
        array<char, 128> t_map {0};
        for(int i = 0; i < s.length(); i++){
            char curr_s = s[i];
            char curr_t = t[i];
            if(s_map[curr_s] && (s_map[curr_s] != curr_t)) return false;
            if(t_map[curr_t] && (t_map[curr_t] != curr_s)) return false;
            s_map[curr_s] = curr_t;
            t_map[curr_t] = curr_s;
        }
        return true;
        
    }
};