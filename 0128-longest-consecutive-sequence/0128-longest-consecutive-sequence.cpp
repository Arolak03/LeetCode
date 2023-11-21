
class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mpp(nums.begin(), nums.end());
        if(nums.size()==0)return 0;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        //     //each atleast one;
        // }
        int maxi=1;
        for(auto it: mpp){
            //jiska prev na ho
            // int x=it.first;
            if(mpp.find(it-1)==mpp.end()){
                int count=1;
                int x=it;
                
                while(mpp.find(x+1)!=mpp.end()){
                    count++;
                    x++;
                }
                maxi=max(maxi,count);
            }
            // maxi=max(maxi,mpp[it.first]);
        }
        return maxi;
    }
};





// int longestConsecutive(vector<int>& nums) {

//         if(nums.size() == 0)
//         { return 0; }

//         int longest = 1;
//         int current = 1;

//         unordered_set<int> sett(nums.begin(), nums.end());

//         for(auto it: sett)
//         {
//             if(sett.find(it-1) == sett.end()) // previous element not in set
//             {
//                 current = 1;    // counter restart
//                 int x = it;

//                 while(sett.find(x+1) != sett.end()) // next element is present
//                 {
//                     x = x + 1;
//                     current++;
//                 }
//                 longest = max(longest,current);
//             }
//         }
//         return longest;
//     }
// };