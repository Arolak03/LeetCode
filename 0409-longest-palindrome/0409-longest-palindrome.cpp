class Solution {
public:
    int longestPalindrome(string s) {
        int n =s.length();
        unordered_map<char, int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int count=0;
        // if (n%2==0) count=0;
        // else count=1;
        int ans=0;
//         for(int i=0;i<n;i++){
//            if(mpp[s[i]]%2==0){
//                 ans+=mpp[s[i]];
//                 mpp.erase(s[i]);
//             }
//             else{
//                 while(mpp[s[i]]>1){
//                     ans+=mpp[s[i]]-1;
//                     mpp.erase(s[i]);
//                 }
//                 count=1;
//             }
            
//         }
//         return ans==0?1:ans+count;
        for(auto it: mpp){
            ans += it.second/2 * 2;
            if(ans%2==0 && it.second%2==1){
                ans++;
            }
        }
        return ans;
    }
};