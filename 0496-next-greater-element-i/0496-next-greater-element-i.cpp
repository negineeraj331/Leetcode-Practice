// monotonic stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    stack<int> st;
    vector<int> nge(10001, -1);

    for(int i=0; i<n2; ++i){
        while(!st.empty() && nums2[st.top()]<nums2[i]){
            int idx=st.top();
            st.pop();
            int ele = nums2[idx]; //KEY
            nge[ele]=nums2[i];
        }
        st.push(i);
    }

    vector<int> ans(n1, -1);
    for(int i=0;i<n1;++i){
        int querykey = nums1[i];
        ans[i] = nge[querykey];
    }
    return ans;
    }
};