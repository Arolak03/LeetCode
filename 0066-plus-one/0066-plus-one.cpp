class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits[n-1]+=1;
        int index=n-1;
        if(digits[n-1]<10)return digits;
        digits[index]%=10;
        index--;
        int carry=1;
        while(index>=0){
            int sum=(digits[index]+carry);
            digits[index]=sum%10;
            carry=sum/10;
            index--;
        }
        if(carry==0)return digits;
        vector<int> arr;
        arr.push_back(1);
        for(int i=0;i<n;i++){
            arr.push_back(digits[i]);
        }
        return arr;
    }
};