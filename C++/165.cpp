class Solution {
public:
    int compareVersion(string version1, string version2) {
        //convert string into string buffer
        
        istringstream iss1(version1), iss2(version2);
        string token1, token2;
        
        while(!iss1.eof() || !iss2.eof()) {
            
            //get string token
            getline(iss1, token1, '.');
            getline(iss2, token2, '.');

            if(stoi(token1) > stoi(token2)) return 1;
            if(stoi(token1) < stoi(token2)) return -1;
            
            //if hiting the end of line, the rest is 0
            token1 = token2 = "0";
        }
        return 0;
    }
};