class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //check zero
        if(s.empty()) return 0;
        // use array to count number of character
        int dict[256]={0};
        int distinct = 0;
        int start = 0;
        int length = 1;
        for(int i = 0; i < s.size(); i++){
            dict[s[i]]++;
            // the first time
            if(dict[s[i]] == 1){
                distinct++;
                // rest start
                while(distinct > 2){
                    dict[s[start]]--;
                    // make sure you erase the previous distinct
                    if(dict[s[start]] == 0) distinct--;
                    start++;
                }
            }
            
            if (i - start + 1 > length)
                length = i - start + 1;
        }
        return length;
        
    }
};

