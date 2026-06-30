class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long reversedNumber = 0; // Use long to prevent overflow
        int original = x;

        while (x > 0) {
            int lastDigit = x % 10;
            reversedNumber = (reversedNumber * 10) + lastDigit;
            x /= 10;
        }

        return original == reversedNumber;
    }
};