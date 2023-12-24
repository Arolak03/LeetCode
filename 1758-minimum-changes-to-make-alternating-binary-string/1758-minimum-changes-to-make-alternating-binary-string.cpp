class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int count=INT_MAX;
        int temp1=0;
        int temp2=0;

        for(int i=0;i<n;i+=2){
            if(s[i]!='0'){
                temp1++;
                // cout<<"yes"<<" ";
            }
            if(i+1<n && s[i+1]!='1'){
                temp1++;
                // cout<<"NO";
            }
        }
        for(int i=0;i<n;i+=2){
            if(s[i]!='1'){
                temp2++;
            
            }
            if(i+1<n && s[i+1]!='0')temp2++;
        }
    
    
        count=min(temp1, temp2);
        return count;
    }
};