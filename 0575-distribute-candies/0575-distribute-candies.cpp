class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int n =c.size();
        int temp=n/2;
//         unordered_map<int, int> mpp;
//         for(int i=0;i<n && temp>0;i++){
//             if(mpp.count(c[i])){
    
//                 continue;
//             }
//             else{
            
//                 mpp[c[i]]++;
//                 temp--;
//             }
//         }
    
//         return mpp.size();
        int i=0;
        int ans=0;
        
        sort(c.begin(), c.end());
        while(i<n && temp>0){
            if(i>0 && c[i]==c[i-1]){
                i++;
                // cout<<c[i]<<"*";
            }
            else{
                ans++;
                cout<<c[i]<<" ";
                i++;
                temp--;
            }
        }
        return ans;
    }
};