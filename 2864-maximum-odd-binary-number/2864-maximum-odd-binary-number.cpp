class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //left m one
        int ones=0;
        int zeros=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')zeros++;
            else ones++;
        }
        string ans="";
//         for(int i=0;i<zeros;i++){
//             if(ones>1){
//                 while(ones>1){
//                     ans.push_back('1');
//                     ones--;
//                 }
//             }
//             else if(ones==1){
//             ans.push_back('0');
                
//             }
//         }
        if(ones==0)return "";
        if(ones>1){
            while(ones>1){
                ans.push_back('1');
                ones--;
            }
        }
        while(zeros-->0){
            ans.push_back('0');
            
        }
        ans.push_back('1');
            return ans;
    }
};