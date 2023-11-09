class Solution {
public:
  int lengthOfLongestSubstring(string s) {
//     int low=0;
//     int high=0;
//     int len=0;
//     unordered_map<char, int> mpp;
//     while(high<s.length()){
//       if(!mpp.count(s[high])){
//         mpp.insert({s[high],high});
//         high++;
         
//       }
//       else{
//         low++;
//       } 
//       len=max(len,high-low+1);
//     }
//     return len;
      vector<int> dict(256,-1);
      int len=0;
      int start=-1;
      for(int i=0;i<s.length();i++){
          if(dict[s[i]]>start){
              start=dict[s[i]];
          }
          dict[s[i]]=i;
          len=max(len,i-start);
      }
      return len;
  }
};