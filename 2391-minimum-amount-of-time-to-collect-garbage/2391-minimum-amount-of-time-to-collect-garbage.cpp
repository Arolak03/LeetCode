class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count=0;
        int glasscount=0;
        int papercount=0;
        int metalcount=0;
        int n =garbage.size();
        for(int i=0;i<n;i++){
            string s = garbage[i];
            count+=s.length();
        }
        map<int , int> mpp;
        mpp[1]=travel[0];
        for(int i=2;i<=travel.size();i++){
            mpp[i]=mpp[i-1]+travel[i-1];
        }
        // for(auto it: mpp)cout<<it.second<<" ";
        for(int i=n-1;i>=0;i--){
            string s = garbage[i];
            for(int j=0;j<s.length();j++){
                if(s[j]=='G'){
                    glasscount=max(mpp[i],glasscount);
                    
                    break;
                }
            }
            
        }
        cout<<glasscount<<" ";
        for(int i=n-1;i>=0;i--){
            string s = garbage[i];
            for(int j=0;j<s.length();j++){
                if(s[j]=='M'){
                    metalcount=max(mpp[i],metalcount);
                    break;
                }
            }
        }
        cout<<metalcount<<" ";
        for(int i=n-1;i>=0;i--){
            string s = garbage[i];
            for(int j=0;j<s.length();j++){
                if(s[j]=='P'){
                    papercount=max(mpp[i],papercount);
                    break;
                }
            }
        }
        cout<<papercount<<" ";
        return count+metalcount+papercount+glasscount;
        
    }
};