class Solution {
public:
    bool isPathCrossing(string s) {
        map<pair<int, int>, int> mpp;
        mpp[{0,0}]=1;
        int x=0;
        int y=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='N'){
                mpp[{x-1,y}]++;
                x--;
            }
            if(mpp[{x,y}]>1)return true;
            if(s[i]=='S'){
                mpp[{x+1,y}]++;
                x++;
            }
            if(mpp[{x,y}]>1)return true;

            if(s[i]=='W'){
                mpp[{x,y-1}]++;
                y--;
            }
            if(mpp[{x,y}]>1)return true;

            if(s[i]=='E'){
                mpp[{x,y+1}]++;
                y++;
            }
            if(mpp[{x,y}]>1)return true;

        }
        // for(auto it: mpp){
        //     if(it.second>1)return true;
        // }
        return false;
        
    }
};