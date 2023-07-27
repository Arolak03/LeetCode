class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int count = batteries.size();
        long long sum = 0;
        for(int i=0;i<count;i++){
            sum+=batteries[i];
        }
        long long ans=0;
        sort(batteries.begin(),batteries.end());
        long long r = sum/n+1;
        long long l = batteries[count-n];// min to a comp
        while(l<r){
            long long mid = l+(r-l)/2;
            //poori poori baat dol;
            int k = count-1;//indices of array
            while(k>=0 && batteries[k]>=mid){
                k--;
            }
            int rem = n-(count-k-1);//no of comp left
            //k peeche s batteries dedi mne to kaunse index = array k size - k -1
            long long temp = 0;
            while(k>=0){
                temp+=batteries[k];
                k--;
            }
            if(rem<=0 || temp>=mid*rem){
                ans= max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return ans;
    }
};