class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int othersum=0;
        // cout<<sum;
        int index;
        for(int i = n;i>=1;i--){
            while(sum>othersum){
                sum=sum-i;
                othersum=othersum+i;
                index = i;
                i--;
                // cout<<index<<endl;
            }
        }
        cout<<sum;
        sum = sum+index;
        cout<<index;
        if(sum==othersum){
            return index;
        }
        else{return -1;}
    }
};