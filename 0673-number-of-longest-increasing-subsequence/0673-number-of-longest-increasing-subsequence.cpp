class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> len(n,1);
        vector<int> count(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i]){
                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        count[i]=0;
                    }
                    if(len[j]+1==len[i]){
                    //agr same length horhi h jo abhi waha present h uske
                    count[i]+=count[j];
                    }
                }
            }
        }
            int maxlen = *max_element(len.begin(),len.end());
            int result=0;
        for(int i=0;i<n;i++){
            if(len[i]==maxlen){
                result+=count[i];
            }
        }
        
    return result; 
    }
};