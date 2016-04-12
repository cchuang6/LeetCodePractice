// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int readChar = 0;
        while(1){
            int curRead = read4(buf);
            int length = min(n - readChar, curRead);
            readChar += length;
            buf += length;
            if(length != 4 || readChar == n) return readChar;
        }
    }
};