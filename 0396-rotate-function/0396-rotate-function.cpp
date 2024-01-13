class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        int rotSum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            rotSum+=i*nums[i];
        }
        int result=rotSum;
        for(int i=1;i<n;i++){
            //kaunsa minue krna h mtln kisse 0 k multiple and baakiyop m ek ek bhad jayega kyunki sbka multiplication coefficient incresese
            rotSum+=sum-n*nums[n-i];
            result=max(result, rotSum);
        }
        return result;
    }
};