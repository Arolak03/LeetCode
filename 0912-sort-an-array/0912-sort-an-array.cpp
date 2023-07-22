class Solution {
public:
    
    void merge(vector<int>& nums, int s, int e){
               int mid = s+(e-s)/2;
        //new array bnaao
        int len1=mid-s+1;
        int len2=e-mid;
        
        vector<int> f(len1);
        vector<int> sec(len2);
        int k1 =s;
        for(int i=0;i<len1;i++){
            f[i]=nums[k1++];
        }
        int k = mid+1;
        for(int i=0;i<len2;i++){
            sec[i]=nums[k++];
        }
        int index1=0;
        int index2=0;
        //both filled now i have to add
        int k3 = s;
        while(index1<len1 && index2<len2){
            if(sec[index2]<f[index1]){
                nums[k3++]=sec[index2++];
            }
            else{
                nums[k3++]=f[index1++];
            }
        }
        while(len1>index1){
            nums[k3++]=f[index1++];
        }
        while(len2>index2){
            nums[k3++]=sec[index2++];
        }
        f.clear();sec.clear();
        
    }
    
    void mergeSort(vector<int>& nums, int s, int e){
        int mid = s+(e-s)/2;
        //break
        if(s>=e){
            return;
        }
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        
        merge(nums,s,e);
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};