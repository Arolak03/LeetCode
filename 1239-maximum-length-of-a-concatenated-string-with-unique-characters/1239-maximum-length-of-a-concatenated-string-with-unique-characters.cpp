class Solution {
public:
    int ans=INT_MIN;
    bool unique(string s){
        return unordered_set<char> (s.begin(), s.end()).size()==s.length();
    }
    
    int solve(string s, vector<string>& arr, int index){
        if(index>=arr.size()){
            ans=max((int)s.length(),ans);
            return ans;
        }
        int val1=solve(s,arr,index+1);

        bool flag=1;
        //hr word k chack krnna h 
        for(auto c: arr[index]){
            if(s.find(c)!=string::npos || !unique(arr[index])){
                flag=0;
                break;
            }
        }
        int val2=INT_MIN;
        if(flag){
            val2=solve(s+arr[index],arr,index+1);
        }
        return max(val1,val2);
    }
    
    
    int maxLength(vector<string>& arr) {
        // int ans=0;
        solve("",arr,0);
        return ans;
    }
};
        
//         int val2 = INT_MIN;
//         if(flag) 
//         {
//             val2 = f(i+1,arr,s+arr[i]);
//         }
//         return max(val1,val2);
//     }
//     int maxLength(vector<string>& arr) {
//         f(0,arr,"");
//         return ans;
//     }
// };