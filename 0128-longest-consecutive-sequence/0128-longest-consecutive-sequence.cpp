class Solution {
  
    private:
 int fun1(vector<int>& nums) {
     
    std::unordered_set<int> s(nums.begin(),nums.end());
    int ans = 1;

   while(s.size()>0) {
       int maxi=1;
       int ele=*(s.begin());  // TAKE ELEMENT
       s.erase(ele);
       int temp=ele-1;
       while(s.count(temp)){ //LESSER 
           maxi++;
           s.erase(temp);
           temp--;
       }
       temp=ele+1;
        while(s.count(temp)){  //GREATER
           maxi++;
           s.erase(temp);
           temp++;
       }
       ans=max(maxi,ans);
    }

    return ans;
}
// void fast(){
//       std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
// }
public:
    int longestConsecutive(vector<int>& nums) {
        // fast();
        if(nums.size()==0)return 0;
        return fun1(nums);
    }
};