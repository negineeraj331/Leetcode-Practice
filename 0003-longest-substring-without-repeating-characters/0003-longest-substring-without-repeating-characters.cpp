class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, 0);
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
           
            left = max(left, lastIndex[s[right]]);
            
            maxLength = max(maxLength, right - left + 1);
            
            lastIndex[s[right]] = right + 1;
        }
        
        return maxLength;
    }
};