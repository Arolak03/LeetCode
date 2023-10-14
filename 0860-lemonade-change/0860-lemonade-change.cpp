class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
//         int count5=0;
//         int count10=0;
//         for(int i=0;i<bills.size();i++){
//             if(bills[i]-5==0)count5++;
//             if(bills[i]-10==0)count10++;
//             if(bills[i]==10)count5--;
//             if(bills[i]==20){
//                 if(count10>0){
//                     count10--;
//                     count5--;
//                 }else{
//                     count5=count5-3;
//                 }
//             }
            
//             if(count5<0)return false;
                
//         }
//         return true;
        unordered_map<int, int> mpp;//5 and 10 bills
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)mpp[5]++;
            if(bills[i]==10){
                mpp[10]++;
                mpp[5]--;
            }
            if(bills[i]==20){
                if(mpp[10]>0){
                    mpp[10]--;
                    mpp[5]--;
                }
                else{
                    mpp[5]-=3;
                }
            }
            if(mpp[5]<0)return false;
            
        }
        return true;
        
    }
};