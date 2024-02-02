class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // int dig = 0;
        // int x=low;
        // int fact=0;
        // while(x){
        //     x/=10;
        //     dig++;
        //     fact+=1;
        //     fact*=10;
        // }
        // //first
        // x=low;
        // int leftfMost=0;
        // while(x>=10){
        //     x/=10;
        // }
        // leftMost=x;
        // int temp=dig-1;
        // int neww=leftMost;
        // while(temp--){
        //     new*=10;
        //     new+=leftMost+1;
        // }
        // vector<int> ans;
        // for(int i=low;i<=high;i++){
        //     int temp=i;
        //     int dig=temp%10;
        //     temp/=10;
        //     bool flag=true;
        //     while(temp){
        //         int dig2=temp%10;
        //         if(dig2+1==dig){
        //             temp/=10;
        //             dig=dig2;
        //         }
        //         else{
        //             flag=false;
        //             break;
        //         }
        //     }
        //     if(flag){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        
        // int dig=0;
        // int x=low;
        // while(x){
        //     dig++;
        //     x/=10;
        // }
        // int fact=0;
        // int num=0;
        // int tempDig=dig;
        // while(tempDig--){
        //     fact+=1;
        //     fact*=10;
        // }
        // fact/=100;
        // vector<int> ans;
        queue<int> q;
        for(int i=1;i<9;i++){
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(top>=low && top<=high)ans.push_back(top);
            if(top>high)break;
            // int rem=top%10;
            if(top%10<9){
                int rem=top%10;
                top=top*10+rem+1;
                q.push(top);
            }
        }
        return ans;
        
        
    }
};