// // monotonic stack
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     stack<int> st;
//     vector<int> nge(10001, -1);

//     for(int i=0; i<n2; ++i){
//         while(!st.empty() && nums2[st.top()]<nums2[i]){
//             int idx=st.top();
//             st.pop();
//             int ele = nums2[idx]; //KEY
//             nge[ele]=nums2[i];
//         }
//         st.push(i);
//     }

//     vector<int> ans(n1, -1);
//     for(int i=0;i<n1;++i){
//         int querykey = nums1[i];
//         ans[i] = nge[querykey];
//     }
//     return ans;
//     }
// };


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> nextGreater;

        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty())
                nextGreater[nums2[i]] = -1;
            else
                nextGreater[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;

        // Answer queries for nums1
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};