class Solution {
public:

    vector<int> nextSmallElem(vector<int>& arr, int n ){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr)s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        for(int it: ans){
            cout<<it<<" ";
        }
        return ans;
    }
    vector<int> prevSmallElem(vector<int>& arr, int n ){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr)s.pop();
            ans[i]=s.top();
            s.push(i);
        }
         for(int it: arr){
            cout<<it<<" ";
        }
        return ans;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> next{n};
        vector<int> prev(n);
        prev = prevSmallElem(heights,n);
        next= nextSmallElem(heights,n);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l = heights[i];
            if(next[i]==-1)next[i]=n;
            int b = next[i]-prev[i]-1;// prev smaller se lekr next smaller wali width hohi na
            int newArea = l*b;
                area = max(area,newArea);
        }
        return area;
    }
};