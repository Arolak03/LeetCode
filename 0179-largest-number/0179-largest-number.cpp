class Solution {
public:
    
    static bool compare(string a, string b){
        
        return a+b>b+a;
    }
        
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        int n =nums.size();
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(),s.end(),compare);
        // reverse(s.begin(), s.end());
        string str;
        for(int i=0;i<n;i++){
            str+=s[i];
        }
        // int x=stol(str);
        // cout<<x;
        // string ss=to_string(x);
        // return ss;
        if(str[0]=='0')return "0";
        return str;
    }
};