class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m =nums2.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<m;i++){
            st.push(nums2[m-i-1]);
        }
        for(int i=0;i<n;i++){
            stack<int> s;
            while(st.top()!=nums1[i]){
                s.push(st.top());
                st.pop();
            }
            s.push(st.top());
            st.pop();
            while(!st.empty()){
                if(st.top()>nums1[i]){
                    ans[i]=st.top();
                    break;
                }
                else {
                    s.push(st.top());
                    st.pop();
                }
            }
            while(!s.empty()){
                st.push(s.top());
                s.pop();
            }
        }
        return ans;
    }
};