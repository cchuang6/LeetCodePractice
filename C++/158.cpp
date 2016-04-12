// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char* innerBuf = new char[4];
    int offset = 0;
    int usedBuff = 0;
    int read(char *buf, int n) {
        int readBytes = 0;
        bool eof = false;
        while(readBytes < n && !eof){
            if(usedBuff == 0){
                offset = 0;
                usedBuff = read4(innerBuf);
                eof = usedBuff == 4 ? false : true;
            }
            int length = min(n - readBytes, usedBuff);
            for(int i = 0; i < length; i++){
                *buf = innerBuf[offset + i];
                buf++;
            }
            usedBuff -= length;
            
            offset = (offset + length) % 4;
            readBytes += length;
        
            
        }
        return readBytes;
    }
};