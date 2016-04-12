class Solution {
public:
    bool isMatch(string s, string p) {
        //convert string to c_str
        const char* s_cstr = s.c_str();
        const char* p_cstr = p.c_str();
        
        const char* star=NULL;
        const char* ss=s_cstr;
        
        while(*s_cstr){
            if ((*p_cstr=='?')||(*p_cstr==*s_cstr)){s_cstr++;p_cstr++;continue;}
            if (*p_cstr=='*'){star=p_cstr++; ss=s_cstr;continue;}
            if (star){ p_cstr = star+1; s_cstr=++ss;continue;}
            return false;
        }
        while (*p_cstr=='*'){p_cstr++;}
        return !*p_cstr;
    }
};