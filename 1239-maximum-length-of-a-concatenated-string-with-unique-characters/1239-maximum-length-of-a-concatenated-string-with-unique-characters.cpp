class Solution {
public:

    bool unique(string s){
        return unordered_set<char> (s.begin(), s.end()).size()==s.length();
    }
    bool dupli(string s,string arr){
        int arr1[26]={0};
        for(char &ch: s){
            if(arr1[ch-'a']>0)return false;
            else{
                arr1[ch-'a']++;
                // cout<<ch<<" ";
            }
        }
        for(int i=0;i<arr.length();i++){
            if(arr1[arr[i]-'a']!=0)return false;
        }
        // cout<<endl;
        return true;
    }
    
    int solve(string s, vector<string>& arr, int index, int& ans){
        if(index>=arr.size()){
            ans=max(ans,(int)s.length());
            return s.length();
        }

        int include=0;
        int exc=0;
        if(!dupli(arr[index], s)){
            exc=solve(s,arr,index+1,ans);
            // cout<<"yes"<<" ";
        }
        else{
            exc=solve(s,arr,index+1,ans);
            include=solve(s+arr[index],arr,index+1,ans);
       }
        cout<<include<<" "<<exc<<s.length()<<endl;
        return max(include,exc);   
    }
    
    
    int maxLength(vector<string>& arr) {
        // int ans=0;
        // int ans=0;
        string temp="";
        int ans=0;
        solve(temp,arr,0,ans);
        return ans;
    }
};
        