class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char ch : s) cnt[ch - 'a']++;

        string half, mid;
        for (int i = 0; i < 26; ++i) {
            char ch = static_cast<char>('a' + i);
            if (cnt[i] & 1) mid = string(1, ch);   
            half.append(cnt[i] / 2, ch);           
        }

        string tail(half.rbegin(), half.rend());
        return half + mid + tail;
    }
};