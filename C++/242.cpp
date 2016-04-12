class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int letters[26] = {};
        
        for(int i=0; i < s.length(); i++){
            letters[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            if(--letters[t[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};