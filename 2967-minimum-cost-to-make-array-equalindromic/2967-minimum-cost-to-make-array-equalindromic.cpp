class Solution {
public:
    
    bool isPalindrome(int x){
        string s =to_string(x);
        int i=0;
        int n=s.length();
        while(i<=n/2){
            if(s[i]!=s[n-i-1])return false;
            i++;
        }
        return true;   
    }
    int next(int x){
        while(!isPalindrome(x)){
            x++;
            // next(x);
        }
        return x;
    }
    int less(int x){
        while(!isPalindrome(x)){
            x--;
            // less(x);
        }
        return x;
    }
    
    long long sum(vector<int>& nums,int x){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=abs(nums[i]-x);
        }
        return count;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n =nums.size();
        int x=next(nums[n/2]);
        int y=less(nums[n/2]);
        long long score = min(sum(nums,x), sum(nums,y));
        return score;
    }
};