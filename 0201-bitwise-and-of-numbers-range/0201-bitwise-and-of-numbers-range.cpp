class Solution {
public:
    
    bool power2k(int x){
        if(x==1)return false;
        while(x){
            if(x%2!=0 && x!=1)return false;
            x=x/2;
        }
        return true;
    }
    int nearest2k(int left){
        long long ans=1;
        if(power2k(left))return left;
        while(ans<left){
            ans*=2;
        }
        return ans/2;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        // int ans=left;
        
        // for(int i=left+1;i<=right;i++){
        //     int one=i;
        //     // int two=i+1;
        //     // while(max(one,two)>0){
        //     //     ans=ans&
        //     // }
        //     // while(one>0){
        //         ans=ans&one;
        //         // one=one>>1;
        //     // }
        // }
        if(left==right)return left;
        if(power2k(left) && power2k(right))return 0;
        // if(power2k(left))return left;
        
        int ans1=nearest2k(left);
        int ans2=nearest2k(right);
        // cout<<ans1<<ans2;
        if(ans1!=ans2)return 0;
        else {
            long long ans=left;
             for(long long i=left+1;i<=right;i++){
                 ans=ans&i;
             }
            return ans;
        }
        // return ans1;
    }
};