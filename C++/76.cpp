class Solution {
public:
    string minWindow(string S, string T) {
        // check zero
        if(S.empty() || T.empty()) return string("");
        //create a character array to track the count
        int needFound[256]={0};
        int hasFound[256]={0};
        int length_T = T.size();
        for(int i = 0; i < length_T; i++){
            needFound[T[i]]++;
        }
        int len = S.size();
        int start = 0;
        int count = 0;
        int window_start = 0;
        
        for(int i = 0; i < S.size(); i++){
            if(needFound[S[i]] == 0) continue;
            if(hasFound[S[i]] < needFound[S[i]]){
                count++;
            }
            hasFound[S[i]]++;

            //found window
            if(count == length_T){
                //search new start
                while(needFound[S[start]] == 0 || hasFound[S[start]] > needFound[S[start]]){
                    if(hasFound[S[start]] > needFound[S[start]])
                        hasFound[S[start]]--;
                    start++;
                }
                if(i - start + 1 < len){
                    len = i - start + 1;
                    window_start = start;
                }
            }
        }
        if(count != length_T) return string("");
        return S.substr(window_start, len);
    }
};