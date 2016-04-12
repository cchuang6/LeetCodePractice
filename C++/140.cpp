class Solution {
    unordered_map <string, vector<string>> cache;
    //key part
    
    bool checkSuffix(string s, unordered_set<string> &dict){
        for(int i = 0; i < s.size(); i++){
            if(dictContains(s.substr(i), dict))
                return true;
        }
        return false;
    }
    
    bool dictContains(string s, unordered_set<string> &dict){
        return dict.find(s) != dict.end();
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string>  res;
        if(s.size() == 0) return res;
        if(cache.find(s) != cache.end()) return cache.find(s)->second;
        
        if(dictContains(s, dict)) res.push_back(s);
        
        for(int i = 1; i < s.size(); i++){
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);
            if(dictContains(prefix, dict) && checkSuffix(suffix, dict)){
                vector<string> words = wordBreak(suffix, dict);
                for(int j = 0; j < words.size(); j++){
                    res.push_back(prefix + " " + words[j]);
                }
            }
        }
        cache.insert({s, res});
        return res;
    }
};