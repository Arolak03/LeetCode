class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=0;
        int idx=0;
        if(haystack.size()<needle.size())return -1;
        for(int i=0;i<haystack.length();i++){
            while(haystack[i+index]==needle[index] && index<needle.length()){
                 cout<<index<<" "<<i<<endl;                
                index++;
                
               
            }
            if(index==needle.length()){
                return i;
                // i=INT_MAX;
            }
            if(haystack[i+index]!=needle[index]){
                
                index=0;
                // cout<<0<<endl;
            }
            
            
        }
        // idx=idx-needle.size();
        return -1; 
    }
};