class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        while (x) {
            // If there is only one digit than it is a palindrome
            if (x / 10 == 0) return true;

            // Compare head and tail
            if (x / pow10(size(x)) != x % 10) return false;

            // There should be the same number of zeros on the right (ignoring the tail)
            // The + 1 is to account for the tail, then we ignore it (dividing by 10)
            // If this value is greater than 0 it means that there is some non-zero digit
            if ((x % pow10(zerosAfterHead(x) + 1)) / 10 > 0) return false;

            x = x / pow10(zerosAfterHead(x) + 1); // Remove tail and zeros before it
            x = x % pow10(size(x)); // Remove head (and zeros after it)
        }
        return true;
    }

private:
    int size(int n) {
        // Number of digits in n
        return (int) floor(log10(n));
    }
    int zerosAfterHead(int n) {
        // If the next digit is non-zero the difference will be equal to 1
        return size(n) - size(n % pow10(size(n))) - 1;
    }
    int pow10(int p) {
        return (int) pow(10, p);
    }
};