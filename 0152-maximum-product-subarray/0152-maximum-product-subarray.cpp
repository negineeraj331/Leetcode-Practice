class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            
            if (num < 0) {
                swap(currMax, currMin);
            }
            
            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);
            
            result = max(result, currMax);
        }
        
        return result;
    }
};