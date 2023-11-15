class Solution {
public:
    
    bool isPalindrome(string& s,int i, int j){
        if(i>=j)return true;
        if(s[i]!=s[j])return false;
        
        if(isPalindrome(s,i+1,j-1))return true;
        else return false;
    }
    
    int countSubstrings(string s) {
        int n =s.length();
        vector<string> arr;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str+=s[j];
                arr.push_back(str);
            }
        }
        // for(auto it: arr)cout<<it<<" ";
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(isPalindrome(arr[i],0,arr[i].length()-1))count++;
        }
        return count;
    }
};