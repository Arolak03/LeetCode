class Solution {
public:
    
    
    // bool validLen(string s1, string s2, int len){
    //     int len1=s1.length();
    //     int len2=s2.length();
    //     if(s1.length()%len!=0 || s2.length()%len!=0)return false;
    //     else{
    //         string base=s1.substr(0,len);
    //         int n1=len1/len;
    //         int n2=len2/len;
    //         return s1==join(base,n1) && s2==join(base,n2);
    //     }
    // }
    // string join(string s, int len){
    //     string ans="";
    //     //n1 times mai base add krungi 
    //     for(int i=0;i<len;i++){
    //         ans+=s;
    //     }
    //     return ans;
    // }
    
    
    
    void gcdd(int n1, int n2, int index, int& prod){
        if(index>n1 || index>n2)return;
        if(n1%index==0 && n2%index==0){
            prod*=index;
            gcdd(n1/index,n2/index,index,prod);
        }
        else{
            gcdd(n1,n2,index+1,prod);
        }
    }
    
    string gcdOfStrings(string str1, string str2) {
        // int n1=str1.length();
        // int n2=str2.length();
        // if(str1+str2 != str2+str1)return "";
        // for(int i=min(n2,n1);i>=1;i--){
        //     if(validLen(str1,str2,i)){
        //         return str1.substr(0,i);
        //     }
        // }
        // return "";
        if(str1+str2 != str2+str1)return "";
        // int gcdLen=gcd(str1.size(), str2.size());
        int prod=1;
        gcdd(str1.length(), str2.length(),2,prod);
        return str1.substr(0,prod);
    }
};