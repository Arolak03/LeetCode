class Solution {
public:
    
    
  
    
    
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
       
        if(str1+str2 != str2+str1)return "";
        int prod=1;
        gcdd(str1.length(), str2.length(),2,prod);
        return str1.substr(0,prod);
    }
};