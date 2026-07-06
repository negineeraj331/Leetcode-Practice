class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num:nums){
            mp[num]++;
        }
        
        vector<vector<int>>bucket(nums.size()+1);

        for(auto it:mp){
            int number=it.first;
            int freq=it.second;

            bucket[freq].push_back(number);
        }

        vector<int> ans;
        for(int i=nums.size();i>=1;i--){
            for(int num: bucket[i]){
                ans.push_back(num);

                if(ans.size()==k)
                return ans;
            }
        }
        return ans;
    }
};