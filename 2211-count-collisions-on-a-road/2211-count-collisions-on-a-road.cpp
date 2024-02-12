class Solution {
public:
    int countCollisions(string s) {
    //     int ans=0;
    // //     stack<char> s;
    //    int i=0;
       
       int n=s.length();
        // while(i<n && s[i]=='L')i++;
    //     if(i==n)return 0;
    //     // while(i<n && s[i]=='R'){
    //     //     s.push(s[i]);
    //     //     i++;
    //     // }
    //     s.push(s[i]);
    //     // if(i==n)return 0;
    //     //enxt is l
    //     int forw=i;
    //     // next to r
    //     while(!s.empty){
    //         if(forw<n && (s[forw]='L' || s[forw]='S')){
    //             if(s[forw]=='S'){
    //                 ans++;
    //                 s.pop();
    //                 s.push('S');

    //             }
    //             else{
    //                 ans+=2;
    //                 s[forw]='S'
    //                 s.pop();
    //                 s.push('S')
    //             }
    //         }
    //         forw++;
    //         if(forw==n)break;
            
    //     }
    int rs=n-1;
    int ls=0;
    int ss=0;
    // for(int i=0;i<n;i++){
    //     if(s[i]=='R')rs++;
    //     else if(s[i]=='L')ls++;
    // }
    // ans=ans+2*min(rs,ls);
    // int count=0;
    // stack<char>s;
    // stack<char>l;
    // // int i=0;
    // int j=n-1;
    // while(j>=0 && s[j]=='R')j--;
    
    // while(i<=j){
    //     if(i<=j && s[i]=='R' && s[j]=='L'){
    //         ans+=2;
    //         r.push('S');
    //         l.push('S');
    //         i++;
    //         j--;
    //     }
    //     else if(i<n && s[i]=='L' && l.empty()){
    //         i++;
    //     } 
    //     else if(j>=0 && s[j]=='R' && r.empty()){
    //         j--;
    //     }
    //     else if(i<n && s[i]=='L' && !l.empty()){
    //         i++;
    //         ans+=1;
    //         l.push('S');
    //     }
    //     else if(j>=0 && s[j]=='R' && !r.empty()){
    //         j--;
    //         ans+=1;
    //         r.push('s');
    //     }
    //     else if(i<n && s[i]=='R' && !r.empty()){
    //         s.push('S');
    //         i++;
    //         ans++;
    //     }
    //     else if(j>=0 && s[j]=='L' && !l.empty()){
    //         ans++;
    //         s.push('S');
    //         j--;
    //     }


    // }
        while(ls<n && s[ls]=='L')ls++;
        if(ls==n)return 0;
        while(rs>=0 && s[rs]=='R')rs--;    
        if(rs==ls)return 0;
        n=rs-ls+1;
        
        for(int k=ls;k<=rs;k++){
            if(s[k]=='S')ss++;
        }
        return n-ss;
    }
};